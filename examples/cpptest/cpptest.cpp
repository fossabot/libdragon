#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

static resolution_t res = RESOLUTION_320x240;
static bitdepth_t bit = DEPTH_32_BPP;

class Test
{
  private:
    int data1;
    float data2;

  public:
    void function1()
    {   data1 = 2;  } 

    float function2()
    { 
        data2 = 3.5;
        return data2;
    }
};

int main(void)
{
  init_interrupts();

  Test o1;

  o1.function1();

  display_init( res, bit, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );

  while(1)
  {

  }
}
