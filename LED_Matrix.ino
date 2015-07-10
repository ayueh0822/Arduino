
// 接 74HC595 的 ST_CP (pin 12,latch pin)
int latchPin = 8;
// 接 74HC595 的 SH_CP (pin 11, clock pin)
int clockPin = 12;
// 接 74HC595 的 DS (pin 14)
int dataPin = 11;

byte print_alphabet[7]={};
byte print_a[7]={B00000000,
                 B00011000,
                 B00100100,
                 B00111000,
                 B00100100,
                 B00100100,
                 B01011000,};

byte print_b[7]={B00001000,
                 B00001000,
                 B00001000,
                 B00111000,
                 B01001000,
                 B01001000,
                 B00111000};

byte print_c[7]={B00000000,
                 B00000000,
                 B00111000,
                 B00000100,
                 B00000100,
                 B00000100,
                 B00111000};

byte print_d[7]={B00100000,
                 B00100000,
                 B00100000,
                 B00111000,
                 B00100100,
                 B00100100,
                 B00111000};

byte print_e[7]={B00000000,
                 B00111000,
                 B01000100,
                 B01111100,
                 B00000100,
                 B00111000,
                 B00000000};

byte print_f[7]={B00010000,
                 B00101000,
                 B00001000,
                 B00111100,
                 B00001000,
                 B00001000,
                 B00001000};

byte print_g[7]={B00110000,
                 B01001000,
                 B01001000,
                 B01110000,
                 B01000000,
                 B01001000,
                 B00110000};

byte print_h[7]={B00000100,
                 B00000100,
                 B00000100,
                 B00010100,
                 B00101100,
                 B00100100,
                 B00100100};

byte print_i[7]={B00000000,
                 B00010000,
                 B00000000,
                 B00010000,
                 B00010000,
                 B00010000,
                 B00010000};
                 
byte print_j[7]={B00000000,
                 B00100000,
                 B00000000,
                 B00100000,
                 B00100000,
                 B00101000,
                 B00010000};
                 
byte print_k[7]={B00001000,
                 B00001000,
                 B01001000,
                 B00101000,
                 B00011000,
                 B00101000,
                 B01001000};

byte print_l[7]={B00000000,
                 B00010000,
                 B00010000,
                 B00010000,
                 B00010000,
                 B00010000,
                 B00010000};
                 
byte print_m[7]={B00000000,
                 B00000000,
                 B00101000,
                 B01010100,
                 B01010100,
                 B01010100,
                 B00000000};
                 
byte print_n[7]={B00000000,
                 B00000000,
                 B00010100,
                 B00101100,
                 B00100100,
                 B00100100,
                 B00000000};
                 
byte print_o[7]={B00000000,
                 B00000000,
                 B00011000,
                 B00100100,
                 B00100100,
                 B00011000,
                 B00000000};

byte print_p[7]={B00000000,
                 B00000000,
                 B00111000,
                 B01001000,
                 B00111000,
                 B00001000,
                 B00001000};
                 
byte print_q[7]={B00000000,
                 B00011000,
                 B00100100,
                 B00111000,
                 B00100000,
                 B10100000,
                 B01100000};
                 
byte print_r[7]={B00000000,
                 B00000000,
                 B00101000,
                 B01011000,
                 B00001000,
                 B00001000,
                 B00000000};
                 
byte print_s[7]={B00000000,
                 B00011000,
                 B00100100,
                 B00001000,
                 B00010000,
                 B00100100,
                 B00011000}; 
                 
byte print_t[7]={B00000000,
                 B00001000,
                 B00111100,
                 B00001000,
                 B00001000,
                 B00101000,
                 B00010000};   
                               
byte print_u[7]={B00000000,
                 B00000000,
                 B00100100,
                 B00100100,
                 B00100100,
                 B01011000,
                 B00000000};
                 
byte print_v[7]={B00000000,
                 B00000000,
                 B00000000,
                 B00101000,
                 B00101000,
                 B00010000,
                 B00000000};
byte print_w[7]={B00000000,
                 B00000000,
                 B01010100,
                 B01010100,
                 B01010100,
                 B00101000,
                 B00000000};
                                  
byte print_x[7]={B00000000,
                 B00000000,
                 B00000000,
                 B00101000,
                 B00010000,
                 B00101000,
                 B00000000};
                 
byte print_y[7]={B00000000,
                 B00101000,
                 B00101000,
                 B00010000,
                 B00001000,
                 B00000100,
                 B00000000};
                 
byte print_z[7]={B00000000,
                 B00000000,
                 B00111100,
                 B00010000,
                 B00001000,
                 B00111100,
                 B00000000};   

byte print_ERROR[7]={B10000010,
                     B01000100,
                     B00101000,
                     B00010000,
                     B00101000,
                     B01000100,
                     B10000010};
                     
byte print_CLEAR[7]={B00000000,
                     B00000000,
                     B00000000,
                     B00000000,
                     B00000000,
                     B00000000,
                     B00000000,};
                     
void setup() 
{
    // 將 latchPin, clockPin, dataPin 設置為輸出
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    //serial 設定
    Serial.begin(9600);
}

void get_alphabet(char key)
{ 
       clear_board(); 
       switch(key)
       {             
                  case 'a' :
                         for(int i=0;i<7;i++){print_alphabet[i] = print_a[i];} break;
                  case 'b' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_b[i];} break;
                  case 'c' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_c[i];} break;
                  case 'd' :                  
                         for(int i=0;i<7;i++){print_alphabet[i] = print_d[i];} break;
                  case 'e' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_e[i];} break;
                  case 'f' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_f[i];} break;
                  case 'g' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_g[i];} break;
                  case 'h' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_h[i];} break; 
                  case 'i' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_i[i];} break; 
                  case 'j' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_j[i];} break; 
                  case 'k' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_k[i];} break;
                  case 'l' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_l[i];} break;
                  case 'm' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_m[i];} break; 
                  case 'n' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_n[i];} break; 
                  case 'o' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_o[i];} break; 
                  case 'p' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_p[i];} break; 
                  case 'q' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_q[i];} break; 
                  case 'r' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_r[i];} break; 
                  case 's' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_s[i];} break; 
                  case 't' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_t[i];} break;
                  case 'u' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_u[i];} break;
                  case 'v' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_v[i];} break;                         
                  case 'w' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_w[i];} break;
                  case 'x' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_x[i];} break;
                  case 'y' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_y[i];} break;
                  case 'z' :                        
                         for(int i=0;i<7;i++){print_alphabet[i] = print_z[i];} break;
       }  
}



void light(byte alphabet[]) 
{
    byte col_print;
    for (int i=1; i<=7 ; i++) 
    {
        // 送資料前要先把 latchPin 拉成低電位
        digitalWrite(latchPin, LOW);
  
        col_print = 1 << i;
        // 使用 shiftOut 函式送出資料      
        shiftOut(dataPin, clockPin, MSBFIRST, col_print);
        shiftOut(dataPin, clockPin, MSBFIRST, alphabet[i-1]);
        
        // 送完資料後要把 latchPin 拉回成高電位
        digitalWrite(latchPin, HIGH);
        delay(1);
    }
 
}

int counter;
void LED_print(byte print_alphabet[]) 
{
   counter=0;
   while(counter<50)
   {
         light(print_alphabet);
         counter++;
   }
}

void clear_board() 
{
  light(print_CLEAR);
  delay(50);
}

void loop()
{
       
         // send data only when you receive data:
         if(Serial.available()>0)
         {
                char input = Serial.read() ;
                if(input!='\n')
                {
                  if(input<97 || input>122)
                  {
                    for(int i=0;i<7;i++)
                      print_alphabet[i] = print_ERROR[i];                     
                  }
                  Serial.println(input);
                  get_alphabet(input);
                }
         }
        LED_print(print_alphabet);
        /*
        for(int i=97;i<123;i++)
        {          
            get_alphabet(i);
            LED_print(print_alphabet);
        } 
        */
}
