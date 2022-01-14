#include <iostream>
#include <thread>
#include <mutex>
#include <utility>
#include <fstream>
#include <filesystem>

const int ThreadCount = 5;
const int LoopCount = 3;

class File
{
    private:
        std::string _fileName;
        std::mutex _mutex;

    public:
        explicit File(std::string fileName) : _fileName(std::move(fileName)), _mutex()
        {
        }

        std::unique_lock<std::mutex> Lock()
        {
            return std::unique_lock<std::mutex>{_mutex};
        }

        void Read()
        {
            std::ifstream textFile{_fileName};
            if (textFile.is_open())
            {
                std::cout << textFile.rdbuf();
                textFile.close();
            }
        }

        void Write(const std::string& content)
        {
            std::fstream textFile;
            textFile.open(_fileName, std::fstream::out);
            if (textFile.is_open())
            {
                textFile << content << '\n';
                textFile.close();
            }
        }
};

File File1{"files/file1.txt"};
File File2{"files/file2.txt"};

void LockWriteRead(int threadId)
{
    for (int i = 0; i < LoopCount; ++i)
    {
        auto lock1 = File1.Lock();
        auto lock2 = File2.Lock();
        File1.Write("Thread: " + std::to_string(threadId) + "; Loop: " + std::to_string(i));
        File2.Write("Thread: " + std::to_string(threadId) + "; Loop: " + std::to_string(i));
        File1.Read();
        File2.Read();
    }
}

int main()
{
    std::filesystem::create_directory("files");

    std::vector<std::thread> threads{};
    for (int i = 1; i <= ThreadCount; ++i)
    {
        threads.emplace_back(std::thread{LockWriteRead, i});
    }

    for (auto& thread: threads)
    {
        thread.join();
    }
}
