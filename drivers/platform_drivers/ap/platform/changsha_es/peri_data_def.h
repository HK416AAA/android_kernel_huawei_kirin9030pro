#ifndef PERI_DATA_DEF_H
#define PERI_DATA_DEF_H 
struct peri_volt {
 unsigned int peri;
 unsigned int peri_m1;
 unsigned int peri_m2;
 unsigned int peri_mem;
};
struct peri_data {
 struct peri_volt volt;
};
#endif
