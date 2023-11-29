#ifndef LIBMATHS_H
#define LIBMATHS_H

#define PI		3.1415926535897932384626433832795
#define PI_S	3.14

/*
#define max(a,b) ({	__typeof__ (a) _a = (a); \
						__typeof__ (b) _b = (b); \
						_a > _b ? _a : _b; 		\
})
*/

#define MAX(x, y) (((x) > (y)) ? x : y)
#define MIN(x, y) (((x) < (y)) ? x : y)

#endif