#ifndef HEADER_H
#define HEADER_H

#ifdef __cplusplus
class Fred
{
public:
	Fred();
	void wilma(int);
private:
	int m_a;
};
#else
typedef struct Fred Fred;
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#if defined(__STDC__) || defined(__cplusplus)
	extern void c_function(Fred *fred);
	extern Fred *cpluscplus_function(Fred *fred);
#else
	extern void c_function();
	extern Fred *cpluscplus_function();
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !HEADER_H
