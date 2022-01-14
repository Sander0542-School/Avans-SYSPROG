// copyright © 2002-2022 Bob Polis

#ifndef __throw__
#define __throw__

// don't call this yourself; use the macros below instead
void __throw_if_min1(int x, const char* file, unsigned int line, const char* message = nullptr);

#define throw_if_min1(___x___)					__throw_if_min1((___x___), __FILE__, __LINE__)
#define throw_if_min1_msg(___x___, ___msg___)	__throw_if_min1((___x___), __FILE__, __LINE__, ___msg___)

#endif /* defined(__throw__) */
