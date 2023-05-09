/** char = 1 byte
  * int = 16 to 32 bits (2 a 4 bytes)
  * short (int) = 16 bits (2 bytes)
  * long (int) = 32 bits (4 bytes)
  *
  * unsigned int/float/double/char = 0 or high
  * signed int/float/double/char = less than 0, 0 or high
  *
  * float, double and long double = different sizes
  * (float is single precision, double is double precision and long double is an extend-precision floating point)
  * #include <limits.h>
  * #include <float.h>
  *
  * Obs.: long long (%ll)
  */

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define sizeof_var(var) ((size_t)(&(var)+1)-(size_t)(&(var))) 

void main()
{
	signed char sChar;
	signed short sShort;
	signed int sInt;
	signed long sLong;
	
	long charLengthMin =  pow(2,(sizeof_var(sChar) * 8))/2 * -1;
	long charLength = pow(2,(sizeof_var(sChar) * 8))/2 - 1;
	long shortLengthMin =  pow(2,(sizeof_var(sShort) * 8))/2 * -1;
	long shortLength =  pow(2,(sizeof_var(sShort) * 8))/2 - 1;
	long intLengthMin =  pow(2,(sizeof_var(sInt) * 8))/2 * -1;
	long intLength =  pow(2,(sizeof_var(sInt) * 8))/2 - 1;
	long longLengthMin =  pow(2,(sizeof_var(sLong) * 8))/2 * -1;
	long longLength =  pow(2,(sizeof_var(sLong) * 8))/2 - 1;
	
	printf("%d bytes for signed char values represents: %d to %d\n", sizeof_var(sChar), charLengthMin, charLength);
	printf("%d bytes for signed short (int) values represents: %d to %d\n", sizeof_var(sShort), shortLengthMin, shortLength);
	printf("%d bytes for signed int values represents: %d to %d\n", sizeof_var(sInt), intLengthMin, intLength);
	printf("%d bytes for signed long (int) values represents: %d to %d\n", sizeof_var(sLong), longLengthMin, longLength);
	
	printf("\n--------------------------------\n\n");
	
	unsigned char uChar;
	unsigned short uShort;
	unsigned int uInt;
	unsigned long uLong;
	
	charLength =  pow(2,(sizeof_var(sChar) * 8)) - 1;
	shortLength =  pow(2,(sizeof_var(sShort) * 8)) - 1;
	intLength =  pow(2,(sizeof_var(sInt) * 8)) - 1;
	longLength =  pow(2,(sizeof_var(sLong) * 8)) - 1;
	
	printf("%d bytes for unsigned char values represents: 0 to %d\n", sizeof_var(sChar), charLength);
	printf("%d bytes for unsigned short (int) values represents: 0 to %d\n", sizeof_var(sShort), shortLength);
	printf("%d bytes for unsigned int values represents: 0 to %d\n", sizeof_var(sInt), intLength);
	printf("%d bytes for unsigned long (int) values represents: 0 to %d\n", sizeof_var(sLong), longLength);
	
	printf("\n--------------------------------\n\n");

	float uFloat, fCount, fLast;
	double uDouble, dCount, dLast;
	long double uLongDouble, lDCount, lDLast;
	
	uFloat = 0.0f, uDouble = 0.0, uLongDouble = 0.0L;
	fCount = 0.0f, dCount = 0.0, lDCount = 0.0L;
	while (uFloat == 0.0) {
		fLast = fCount;
		fCount += 1111e28f;
		uFloat = (uFloat + fCount) - fCount;
	}
	printf("Maximum range of float variable: %.1e\n", fLast);
	
	while (uDouble == 0.0) {
		dLast = dCount;
		dCount += 1111e300;
		uDouble = (uDouble + dCount) - dCount;
	}
	printf("Maximum range of double variable: %.1e\n", dLast);
	
	while (uLongDouble == 0.0) {
		lDLast = lDCount;
		lDCount += 1111e4929L;
		uLongDouble = (uLongDouble + lDCount) - lDCount;
	}
	printf("Maximum range of long double variable: %.1e\n", lDLast);
	
	printf("\n--------------------------------\n\n");
	printf("Range of C data types according to the <limits.h> library (actual size varies depending on the computer/compiler)\n\n");
	printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char range: %d to %u\n", 0, UCHAR_MAX);
	printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short range: %d to %u\n", 0, USHRT_MAX);
	printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
	printf("Unsigned int range: %u to %u\n", 0, UINT_MAX);
	printf("Signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long range: %u to %lu\n", 0, ULONG_MAX);
}
