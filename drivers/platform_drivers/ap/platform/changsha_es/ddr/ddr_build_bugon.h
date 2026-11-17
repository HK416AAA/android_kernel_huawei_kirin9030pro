#ifndef DDR_EDA
#define DDR_BUILD_BUG_ON(e) ((void)(sizeof(struct { int:1; int:-((int)!!(e)); })))
#else
#define DDR_BUILD_BUG_ON(e) 
#endif
