#include<stdio.h>
#include<stdlib.h>
#include<emscripten/emscripten.h>

int EMSCRIPTEN_KEEPALIVE mandelbrot ()
{
    int w, h, bit_num = 0;
    char byte_acc = 0;
    int i, iter = 50;
    double x, y, limit = 4;
    double Zr, Zi, Cr, Ci, Tr, Ti;
    
    w = h = 16000;

    printf("P4\n%d %d\n",w,h);
    
    char * buffer = malloc((w / 8  + 1)* sizeof(char));
    
    for(y=0;y<h;++y) 
    {
        int pos = 0;
        for(x=0;x<w;++x)
        {
            Zr = Zi = Tr = Ti = 0.0;
            Cr = (2.0*x/w - 1.5); Ci=(2.0*y/h - 1.0);
        
            for (i=0;i<iter && (Tr+Ti <= limit*limit);++i)
            {
                Zi = 2.0*Zr*Zi + Ci;
                Zr = Tr - Ti + Cr;
                Tr = Zr * Zr;
                Ti = Zi * Zi;
            }
       
            byte_acc <<= 1; 
            if(Tr+Ti <= limit*limit) byte_acc |= 0x01;
                
            ++bit_num; 

            if(bit_num == 8)
            {
                buffer[pos++] = byte_acc;
                //putc(byte_acc,stdout);
                byte_acc = 0;
                bit_num = 0;
            }
            else if(x == w-1)
            {
                byte_acc <<= (8-w%8);
                //putc(byte_acc,stdout);
                buffer[pos++] = byte_acc;
                byte_acc = 0;
                bit_num = 0;
            }
        }
        buffer[pos++] = '\0';
        printf("%.*s",pos,buffer);
    }
    free(buffer);
  return 0; 	
}
