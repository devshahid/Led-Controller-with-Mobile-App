
#include <FastLED.h>
int d=100;
#define NUM_LEDS 100
//#define NUM_STRIPS 51
#define NUM_STRIPS 13
#define initial_value 0
#define final_value 61
#define TRAIL    70
int data;
int z=0;
int g=0;
int b=0;//brightness
int p=0;//pattern
int x=1;
CRGB leds[NUM_LEDS];
CLEDController *controllers[NUM_STRIPS];
uint8_t gBrightness = 50;
        int arr[20] = { 0 };
        int c_blue=0;
        int c_red=0;
        int c_green=0;
        
        int g_red=0;
        int g_blue=0;
        int g_green=0;

        int high=255;
        int med= 140;
        int low= 20;
void setup() 
{ 
  
  controllers[0] = &FastLED.addLeds<WS2812,2>(leds, NUM_LEDS);
  controllers[1] = &FastLED.addLeds<WS2812,3>(leds, NUM_LEDS);
  controllers[2] = &FastLED.addLeds<WS2812,4>(leds, NUM_LEDS);
  controllers[3] = &FastLED.addLeds<WS2812,5>(leds, NUM_LEDS);
  controllers[4] = &FastLED.addLeds<WS2812,6>(leds, NUM_LEDS);
  controllers[5] = &FastLED.addLeds<WS2812,7>(leds, NUM_LEDS);
  controllers[6] = &FastLED.addLeds<WS2812,8>(leds, NUM_LEDS);
  controllers[7] = &FastLED.addLeds<WS2812,9>(leds, NUM_LEDS);
  controllers[8] = &FastLED.addLeds<WS2812,10>(leds, NUM_LEDS);
  controllers[9] = &FastLED.addLeds<WS2812,11>(leds, NUM_LEDS);
  controllers[10] = &FastLED.addLeds<WS2812,12>(leds, NUM_LEDS);
  controllers[11] = &FastLED.addLeds<WS2812,13>(leds, NUM_LEDS);
  controllers[12] = &FastLED.addLeds<WS2812,14>(leds, NUM_LEDS);
  controllers[13] = &FastLED.addLeds<WS2812,15>(leds, NUM_LEDS);
//  controllers[14] = &FastLED.addLeds<WS2812,16>(leds, NUM_LEDS);
//  controllers[15] = &FastLED.addLeds<WS2812,17>(leds, NUM_LEDS);
//  controllers[16] = &FastLED.addLeds<WS2812,18>(leds, NUM_LEDS);
//  controllers[17] = &FastLED.addLeds<WS2812,19>(leds, NUM_LEDS);
//  controllers[18] = &FastLED.addLeds<WS2812,20>(leds, NUM_LEDS);
//  controllers[19] = &FastLED.addLeds<WS2812,21>(leds, NUM_LEDS);
//  controllers[20] = &FastLED.addLeds<WS2812,22>(leds, NUM_LEDS);
//  controllers[21] = &FastLED.addLeds<WS2812,23>(leds, NUM_LEDS);
//  controllers[22] = &FastLED.addLeds<WS2812,24>(leds, NUM_LEDS);
//  controllers[23] = &FastLED.addLeds<WS2812,25>(leds, NUM_LEDS);
//  controllers[24] = &FastLED.addLeds<WS2812,26>(leds, NUM_LEDS);
//  controllers[25] = &FastLED.addLeds<WS2812,27>(leds, NUM_LEDS);
//  controllers[26] = &FastLED.addLeds<WS2812,28>(leds, NUM_LEDS);
//  controllers[27] = &FastLED.addLeds<WS2812,29>(leds, NUM_LEDS);
//  controllers[28] = &FastLED.addLeds<WS2812,30>(leds, NUM_LEDS);
//  controllers[29] = &FastLED.addLeds<WS2812,31>(leds, NUM_LEDS);
//  controllers[30] = &FastLED.addLeds<WS2812,32>(leds, NUM_LEDS);
//  controllers[31] = &FastLED.addLeds<WS2812,33>(leds, NUM_LEDS);
//  controllers[32] = &FastLED.addLeds<WS2812,34>(leds, NUM_LEDS);
//  controllers[33] = &FastLED.addLeds<WS2812,35>(leds, NUM_LEDS);
//  controllers[34] = &FastLED.addLeds<WS2812,36>(leds, NUM_LEDS);
//  controllers[35] = &FastLED.addLeds<WS2812,37>(leds, NUM_LEDS);
//  controllers[36] = &FastLED.addLeds<WS2812,38>(leds, NUM_LEDS);
//  controllers[37] = &FastLED.addLeds<WS2812,39>(leds, NUM_LEDS);
//  controllers[38] = &FastLED.addLeds<WS2812,40>(leds, NUM_LEDS);
//  controllers[39] = &FastLED.addLeds<WS2812,41>(leds, NUM_LEDS);
//  controllers[40] = &FastLED.addLeds<WS2812,42>(leds, NUM_LEDS);
//  controllers[41] = &FastLED.addLeds<WS2812,43>(leds, NUM_LEDS);
//  controllers[42] = &FastLED.addLeds<WS2812,44>(leds, NUM_LEDS);
//  controllers[43] = &FastLED.addLeds<WS2812,45>(leds, NUM_LEDS);
//  controllers[44] = &FastLED.addLeds<WS2812,46>(leds, NUM_LEDS);
//  controllers[45] = &FastLED.addLeds<WS2812,47>(leds, NUM_LEDS);
//  controllers[46] = &FastLED.addLeds<WS2812,48>(leds, NUM_LEDS);
//  controllers[47] = &FastLED.addLeds<WS2812,49>(leds, NUM_LEDS);
//  controllers[48] = &FastLED.addLeds<WS2812,50>(leds, NUM_LEDS);
//  controllers[49] = &FastLED.addLeds<WS2812,51>(leds, NUM_LEDS);
//  controllers[50] = &FastLED.addLeds<WS2812,52>(leds, NUM_LEDS);
//  controllers[51] = &FastLED.addLeds<WS2812,53>(leds, NUM_LEDS);

   pinMode(A0, INPUT); 
  Serial.begin(9600);
 
}
void loop()
{
  if(Serial.available())
   {
    Serial.println("INSIDE");
      data = (int)Serial.read();
      Serial.println(data);
      if(data==250 || data ==251 || data==252 || data==253)
      {
            if(data==250)
            {
              b=1;
              Serial.println(b);
            }
            else if (data==251)
            {
              b=2;
              Serial.println(b);
            }
            else if(data==252)
            {
              b=3;
              Serial.println(b);
            }
            else if(data==253)
            {
              b=4;
              Serial.println(b);
            }
      }
      else if(data==10)
      {
        p=1;//running red
      }
      else if(data==20)
      {
        p=2;//running blue
      }
      else if(data==30)
      {
        p=3;//running green
      }
      else if(data==40)
      {
        p=4;//running yellow
      }
      else if(data==50)
      {
        p=5;//running pink
      }
      else if(data==60)
      {
        p=6;//running orange
      }
      else if(data==70)
      {
        p=7;//running purple
      }
      else if(data==80)
      {
        p=8;//running ocean
      }
      //************red SOlid****************////
      
      else if(data==21)
      {
        p=9;//Solid red
      }
      else if(data==22)
      {
        p=10;//Solid blue
      }
      else if(data==23)
      {
        p=11;//Solid green
      }
      else if(data==24)
      {
        p=12;//Solid yellow
      }
      else if(data==25)
      {
        p=13;//Solid pink
      }
      else if(data==26)
      {
        p=14;//Solid orange
      }
      else if(data==27)
      {
        p=15;//Solid purple
      }
      else if(data==28)
      {
        p=16;//Solid ocean
      }
      //*************beats*************
      else if(data==31)
      {
        p=17;//beats red
      }
      else if(data==32)
      {
        p=18;//beats blue
      }
      else if(data==33)
      {
        p=19;//beats green
      }
      else if(data==34)
      {
        p=20;//beats yellow
      }
      else if(data==35)
      {
        p=21;//beats pink
      }
      else if(data==36)
      {
        p=22;//beats orange
      }
      else if(data==37)
      {
        p=23;//beats purple
      }
      else if(data==38)
      {
        p=24;//beats ocean
      }
      //***********waves*****
      else if(data==61)
      {
        p=25;//wave red
      }
      else if(data==62)
      {
        p=26;//wave blue
      }
      else if(data==63)
      {
        p=27;//wave green
      }
      else if(data==64)
      {
        p=28;//wave yellow
      }
      else if(data==65)
      {
        p=29;//wave pink
      }
      else if(data==66)
      {
        p=30;//wave orange
      }
      else if(data==67)
      {
        p=31;//wave purple
      }
      else if(data==68)
      {
        p=32;//wave ocean
      }
      //********one by one*****
      else if(data==71)
      {
        p=33;//one by one red
      }
      else if(data==72)
      {
        p=34;//one by one blue
      }
      else if(data==73)
      {
        p=35;//one by one green
      }
      else if(data==74)
      {
        p=36;//one by one yellow
      }
      else if(data==75)
      {
        p=37;//one by one pink
      }
      else if(data == 76)
      {
        p=38;//one by one orange
      }
      else if(data == 77)
      {
        p=39;//one by one purple
      }
      else if(data==78)
      {
        p=40;//one by one ocean
      }
      Serial.println(data);
   }
   else
   {
    
        Serial.println("OUT");
        if(x==0)
        {
          
        }
        else if(b==1 && p==1)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_redc();
        }
        else if(b==2 && p==1)
        {
          FastLED.setBrightness(med);
          running_tail_redc();
          Serial.println("med");
        }
        else if(b==3 && p==1)
        {
          FastLED.setBrightness(low);
          running_tail_redc();
          Serial.println("low");
        }
        else if(b==4 && p==1)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }

        ///////////////////blue//////////

        else if(b==1 && p==2)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_blue();
        }
        else if(b==2 && p==2)
        {
          FastLED.setBrightness(med);
          running_tail_blue();
          Serial.println("med");
        }
        else if(b==3 && p==2)
        {
          FastLED.setBrightness(low);
          running_tail_blue();
          Serial.println("low");
        }
        //false code
        else if(b==4 && p==2)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        
        /////////greeen////////
        else if(b==1 && p==3)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_green();
        }
        else if(b==2 && p==3)
        {
          FastLED.setBrightness(med);
          running_tail_green();
          Serial.println("med");
        }
        else if(b==3 && p==3)
        {
          FastLED.setBrightness(low);
          running_tail_green();
          Serial.println("low");
        }
        else if(b==4 && p==3)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        ////////yellow running////////
        else if(b==1 && p==4)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_yellow();
        }
        else if(b==2 && p==4)
        {
          FastLED.setBrightness(med);
          running_tail_yellow();
          Serial.println("med");
        }
        else if(b==3 && p==4)
        {
          FastLED.setBrightness(low);
          running_tail_yellow();
          Serial.println("low");
        }
        else if(b==4 && p==3)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //////pink running///
        else if(b==1 && p==5)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_pink();
        }
        else if(b==2 && p==5)
        {
          FastLED.setBrightness(med);
          running_tail_pink();
          Serial.println("med");
        }
        else if(b==3 && p==5)
        {
          FastLED.setBrightness(low);
          running_tail_pink();
          Serial.println("low");
        }
        else if(b==4 && p==3)
        {
          FastLED.setBrightness(20);
          running_tail_redc();
          Serial.println("dim");
        }
        /////// orangee running//////
        else if(b==1 && p==6)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_orange();
        }
        else if(b==2 && p==6)
        {
          FastLED.setBrightness(med);
          running_tail_orange();
          Serial.println("med");
        }
        else if(b==3 && p==6)
        {
          FastLED.setBrightness(low);
          running_tail_orange();
          Serial.println("low");
        }
        else if(b==4 && p==3)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        ////////// purple running/////
        else if(b==1 && p==7)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_purple();
        }
        else if(b==2 && p==7)
        {
          FastLED.setBrightness(med);
          running_tail_purple();
          Serial.println("med");
        }
        else if(b==3 && p==7)
        {
          FastLED.setBrightness(low);
          running_tail_purple();
          Serial.println("low");
        }
        else if(b==4 && p==7)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        /////////ocean running////////
        else if(b==1 && p==8)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          running_tail_ocean();
        }
        else if(b==2 && p==8)
        {
          FastLED.setBrightness(med);
          running_tail_ocean();
          Serial.println("med");
        }
        else if(b==3 && p==8)
        {
          FastLED.setBrightness(low);
          running_tail_ocean();
          Serial.println("low");
        }
        else if(b==4 && p==3)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid red**********
        else if(b==1 && p==9)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_red();
        }
        else if(b==2 && p==9)
        {
          FastLED.setBrightness(med);
          solid_colour_red();
          Serial.println("med");
        }
        else if(b==3 && p==9)
        {
          FastLED.setBrightness(low);
          solid_colour_red();
          Serial.println("low");
        }
        else if(b==4 && p==9)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid blue**********
        
        else if(b==1 && p==10)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_blue();
        }
        else if(b==2 && p==10)
        {
          FastLED.setBrightness(med);
          solid_colour_blue();
          Serial.println("med");
        }
        else if(b==3 && p==10)
        {
          FastLED.setBrightness(low);
          solid_colour_blue();
          Serial.println("low");
        }
        else if(b==4 && p==10)
        {
          FastLED.setBrightness(20);
          running_tail_blue();
          Serial.println("dim");
        }
        //********solid green**********
        else if(b==1 && p==11)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_green();
        }
        else if(b==2 && p==11)
        {
          FastLED.setBrightness(med);
          solid_colour_green();
          Serial.println("med");
        }
        else if(b==3 && p==11)
        {
          FastLED.setBrightness(low);
          solid_colour_green();
          Serial.println("low");
        }
        else if(b==4 && p==11)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid yellow**********
        else if(b==1 && p==12)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_yellow();
        }
        else if(b==2 && p==12)
        {
          FastLED.setBrightness(med);
          solid_colour_yellow();
          Serial.println("med");
        }
        else if(b==3 && p==12)
        {
          FastLED.setBrightness(low);
          solid_colour_yellow();
          Serial.println("low");
        }
        else if(b==4 && p==12)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid pink**********
        else if(b==1 && p==13)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_pink();
        }
        else if(b==2 && p==13)
        {
          FastLED.setBrightness(med);
          solid_colour_pink();
          Serial.println("med");
        }
        else if(b==3 && p==13)
        {
          FastLED.setBrightness(low);
          solid_colour_pink();
          Serial.println("low");
        }
        else if(b==4 && p==13)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid orange**********
        else if(b==1 && p==14)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_orange();
        }
        else if(b==2 && p==14)
        {
          FastLED.setBrightness(med);
          solid_colour_orange();
          Serial.println("med");
        }
        else if(b==3 && p==14)
        {
          FastLED.setBrightness(low);
          solid_colour_orange();
          Serial.println("low");
        }
        else if(b==4 && p==14)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //********solid purple**********
        else if(b==1 && p==15)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_purple();
        }
        else if(b==2 && p==15)
        {
          FastLED.setBrightness(med);
          solid_colour_purple();
          Serial.println("med");
        }
        else if(b==3 && p==15)
        {
          FastLED.setBrightness(low);
          solid_colour_purple();
          Serial.println("low");
        }
        else if(b==4 && p==15)
        {
          FastLED.setBrightness(20);
          running_tail_purple();
          Serial.println("dim");
        }
        //********solid ocean**********
        else if(b==1 && p==16)
        {
          Serial.println("HIGH");
          FastLED.setBrightness(high);
          solid_colour_ocean();
        }
        else if(b==2 && p==16)
        {
          FastLED.setBrightness(med);
          solid_colour_ocean();
          Serial.println("med");
        }
        else if(b==3 && p==16)
        {
          FastLED.setBrightness(low);
          solid_colour_ocean();
          Serial.println("low");
        }
        else if(b==4 && p==16)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //***********beats*********
        //************red BEats*******
        else if(b==1 && p==17)
        {
          FastLED.setBrightness(high);
          beats_red();
          Serial.println("high");
        }
        else if(b==2 && p==17)
        {
          FastLED.setBrightness(med);
          beats_red();
          Serial.println("med");
        }
        else if(b==3 && p==17)
        {
          FastLED.setBrightness(low);
          beats_red();
          Serial.println("low");
        }
        else if(b==4 && p==17)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************blue BEats*******
        else if(b==1 && p==18)
        {
          FastLED.setBrightness(high);
          beats_blue();
          Serial.println("high");
        }
        else if(b==2 && p==18)
        {
          FastLED.setBrightness(med);
          beats_blue();
          Serial.println("med");
        }
        else if(b==3 && p==18)
        {
          FastLED.setBrightness(low);
          beats_blue();
          Serial.println("low");
        }
        else if(b==4 && p==18)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************green BEats*******
        else if(b==1 && p==19)
        {
          FastLED.setBrightness(high);
          beats_green();
          Serial.println("high");
        }
        else if(b==2 && p==19)
        {
          FastLED.setBrightness(med);
          beats_green();
          Serial.println("med");
        }
        else if(b==3 && p==19)
        {
          FastLED.setBrightness(low);
          beats_green();
          Serial.println("low");
        }
        else if(b==4 && p==19)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************yellow BEats*******
        else if(b==1 && p==20)
        {
          FastLED.setBrightness(high);
          beats_yellow();
          Serial.println("high");
        }
        else if(b==2 && p==20)
        {
          FastLED.setBrightness(med);
          beats_yellow();
          Serial.println("med");
        }
        else if(b==3 && p==20)
        {
          FastLED.setBrightness(low);
          beats_yellow();
          Serial.println("low");
        }
        else if(b==4 && p==20)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************pink BEats*******
        else if(b==1 && p==21)
        {
          FastLED.setBrightness(high);
          beats_pink();
          Serial.println("high");
        }
        else if(b==2 && p==21)
        {
          FastLED.setBrightness(med);
          beats_pink();
          Serial.println("med");
        }
        else if(b==3 && p==21)
        {
          FastLED.setBrightness(low);
          beats_pink();
          Serial.println("low");
        }
        else if(b==4 && p==21)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************orange BEats*******
        else if(b==1 && p==22)
        {
          FastLED.setBrightness(high);
          beats_orange();
          Serial.println("high");
        }
        else if(b==2 && p==22)
        {
          FastLED.setBrightness(med);
          beats_orange();
          Serial.println("med");
        }
        else if(b==3 && p==22)
        {
          FastLED.setBrightness(low);
          beats_orange();
          Serial.println("low");
        }
        else if(b==4 && p==22)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************purple BEats*******
        else if(b==1 && p==23)
        {
          FastLED.setBrightness(high);
          beats_purple();
          Serial.println("high");
        }
        else if(b==2 && p==23)
        {
          FastLED.setBrightness(med);
          beats_purple();
          Serial.println("med");
        }
        else if(b==3 && p==23)
        {
          FastLED.setBrightness(low);
          beats_purple();
          Serial.println("low");
        }
        else if(b==4 && p==23)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************ocean BEats*******
        else if(b==1 && p==24)
        {
          FastLED.setBrightness(high);
          beats_ocean();
          Serial.println("high");
        }
        else if(b==2 && p==24)
        {
          FastLED.setBrightness(med);
          beats_ocean();
          Serial.println("med");
        }
        else if(b==3 && p==24)
        {
          FastLED.setBrightness(low);
          beats_ocean();
          Serial.println("low");
        }
        else if(b==4 && p==24)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        
        //************Red Wave*******
        else if(b==1 && p==25)
        {
          gBrightness=high;
          wave_red();
          Serial.println("high");
        }
        else if(b==2 && p==25)
        {
          gBrightness=med;
          wave_red();
          Serial.println("med");
        }
        else if(b==3 && p==25)
        {
          gBrightness=low;
          wave_red();
          Serial.println("low");
        }
        else if(b==4 && p==25)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Blue Wave*******
        else if(b==1 && p==26)
        {
          gBrightness=high;
          wave_blue();
          Serial.println("high");
        }
        else if(b==2 && p==26)
        {
          gBrightness=med;
          wave_blue();
          Serial.println("med");
        }
        else if(b==3 && p==26)
        {
          gBrightness=low;
          wave_blue();
          Serial.println("low");
        }
        else if(b==4 && p==26)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Green Wave*******
        else if(b==1 && p==27)
        {
          gBrightness=high;
          wave_green();
          Serial.println("high");
        }
        else if(b==2 && p==27)
        {
          gBrightness=med;
          wave_green();
          Serial.println("med");
        }
        else if(b==3 && p==27)
        {
          gBrightness=low;
          wave_green();
          Serial.println("low");
        }
        else if(b==4 && p==27)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Yellow Wave*******
        else if(b==1 && p==28)
        {
          gBrightness=high;
          wave_yellow();
          Serial.println("high");
        }
        else if(b==2 && p==28)
        {
          gBrightness=med;
          wave_yellow();
          Serial.println("med");
        }
        else if(b==3 && p==28)
        {
          gBrightness=low;
          wave_yellow();
          Serial.println("low");
        }
        else if(b==4 && p==28)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Pink Wave*******
        else if(b==1 && p==29)
        {
          gBrightness=high;
          wave_pink();
          Serial.println("high");
        }
        else if(b==2 && p==29)
        {
          gBrightness=med;
          wave_pink();
          Serial.println("med");
        }
        else if(b==3 && p==29)
        {
          gBrightness=low;
          wave_pink();
          Serial.println("low");
        }
        else if(b==4 && p==29)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Orange Wave*******
        else if(b==1 && p==30)
        {
          gBrightness=high;
          wave_orange();
          Serial.println("high");
        }
        else if(b==2 && p==30)
        {
          gBrightness=med;
          wave_orange();
          Serial.println("med");
        }
        else if(b==3 && p==30)
        {
          gBrightness=low;
          wave_orange();
          Serial.println("low");
        }
        else if(b==4 && p==30)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************purple Wave*******
        else if(b==1 && p==31)
        {
         gBrightness=high;
          wave_purple();
          Serial.println("high");
        }
        else if(b==2 && p==31)
        {
          gBrightness=med;
          wave_purple();
          Serial.println("med");
        }
        else if(b==3 && p==31)
        {
          gBrightness=low;
          wave_purple();
          Serial.println("low");
        }
        else if(b==4 && p==31)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        //************Ocean Wave*******
        else if(b==1 && p==32)
        {
          gBrightness=high;
          wave_ocean();
          Serial.println("high");
        }
        else if(b==2 && p==32)
        {
          gBrightness=med;
          wave_ocean();
          Serial.println("med");
        }
        else if(b==3 && p==32)
        {
          gBrightness=low;
          wave_ocean();
          Serial.println("low");
        }
        else if(b==4 && p==32)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        
        //************blink red*******
        else if(b==1 && p==33)
        {
          gBrightness=high;
          blink_one_by_one_red();
          Serial.println("high");
        }
        else if(b==2 && p==33)
        {
          gBrightness=med;
          blink_one_by_one_red();
          Serial.println("med");
        }
        else if(b==3 && p==33)
        {
          gBrightness=low;
          blink_one_by_one_red();
          Serial.println("low");
        }
        else if(b==4 && p==33)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink blue*******
        else if(b==1 && p==34)
        {
          gBrightness=high;
          blink_one_by_one_blue();
          Serial.println("high");
        }
        else if(b==2 && p==34)
        {
          gBrightness=med;
          blink_one_by_one_blue();
          Serial.println("med");
        }
        else if(b==3 && p==34)
        {
          gBrightness=low;
          blink_one_by_one_blue();
          Serial.println("low");
        }
        else if(b==4 && p==34)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink green*******
        else if(b==1 && p==35)
        {
          gBrightness=high;
          blink_one_by_one_green();
          Serial.println("high");
        }
        else if(b==2 && p==35)
        {
          gBrightness=med;
          blink_one_by_one_green();
          Serial.println("med");
        }
        else if(b==3 && p==35)
        {
          gBrightness=low;
          blink_one_by_one_green();
          Serial.println("low");
        }
        else if(b==4 && p==35)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink yellow*******
        else if(b==1 && p==36)
        {
          gBrightness=high;
          blink_one_by_one_yellow();
          Serial.println("high");
        }
        else if(b==2 && p==36)
        {
          gBrightness=med;
          blink_one_by_one_yellow();
          Serial.println("med");
        }
        else if(b==3 && p==36)
        {
          gBrightness=low;
          blink_one_by_one_yellow();
          Serial.println("low");
        }
        else if(b==4 && p==36)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink pink*******
        else if(b==1 && p==37)
        {
          gBrightness=high;
          blink_one_by_one_pink();
          Serial.println("high");
        }
        else if(b==2 && p==37)
        {
          gBrightness=med;
          blink_one_by_one_pink();
          Serial.println("med");
        }
        else if(b==3 && p==37)
        {
          gBrightness=low;
          blink_one_by_one_pink();
          Serial.println("low");
        }
        else if(b==4 && p==37)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************orange red*******
        else if(b==1 && p==38)
        {
          gBrightness=high;
          blink_one_by_one_orange();
          Serial.println("high");
        }
        else if(b==2 && p==38)
        {
          gBrightness=med;
          blink_one_by_one_orange();
          Serial.println("med");
        }
        else if(b==3 && p==38)
        {
         gBrightness=low;
          blink_one_by_one_orange();
          Serial.println("low");
        }
        else if(b==4 && p==38)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink purple*******
        else if(b==1 && p==39)
        {
          gBrightness=high;
          blink_one_by_one_purple();
          Serial.println("high");
        }
        else if(b==2 && p==39)
        {
          gBrightness=med;
          blink_one_by_one_purple();
          Serial.println("med");
        }
        else if(b==3 && p==39)
        {
          gBrightness=low;
          blink_one_by_one_purple();
          Serial.println("low");
        }
        else if(b==4 && p==39)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
         //************blink ocean*******
        else if(b==1 && p==40)
        {
          gBrightness=high;
          blink_one_by_one_ocean();
          Serial.println("high");
        }
        else if(b==2 && p==40)
        {
          gBrightness=med;
          blink_one_by_one_ocean();
          Serial.println("med");
        }
        else if(b==3 && p==40)
        {
          gBrightness=low;
          blink_one_by_one_ocean();
          Serial.println("low");
        }
        else if(b==4 && p==40)
        {
          FastLED.setBrightness(20);
          running_tail_pink();
          Serial.println("dim");
        }
        
   }//else
   
}//loop
/////////////////////////
void beats_red()
{ 
  Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,255,0));
    FastLED.show();
    delay(5);
  }
  else
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
    FastLED.show(); 
  }
}
void beats_blue()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
    FastLED.show();
    delay(5);
  }
  else
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
    FastLED.show(); 
  }
}
///////////////////////////////////////
void beats_green()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,0,255));
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}
////////////////////////////
void beats_yellow()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,210,60));//brg
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}
///////////////////////////////
void beats_orange()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(0,255,45));
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}

void beats_purple()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(128,128,0));
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}
void beats_pink()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(50,255,20));
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}
void beats_ocean()
{ Serial.println("beats");
  if (digitalRead(A0)==HIGH)
  {
    fill_solid(leds, NUM_LEDS, CRGB(255,0,255));
     FastLED.show();
     
     delay(5);
  }
   else
   {
     fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
     FastLED.show(); 
   }
}

//---------------------------------------------------------------------------------------------------
void solid_colour_red()
{    Serial.println("solid color red");
    fill_solid(leds, NUM_LEDS, CRGB(0,255,0));
     FastLED.show();
}
void solid_colour_blue()
{    Serial.println("solid color blue");
    fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
     FastLED.show();
}
void solid_colour_green()
{    Serial.println("solid color green");
    fill_solid(leds, NUM_LEDS, CRGB(0,0,255));
     FastLED.show();
}
void solid_colour_yellow()
{    Serial.println("solid color yellow");
    fill_solid(leds, NUM_LEDS, CRGB(0,210,60));
     FastLED.show();
}
void solid_colour_orange()
{    Serial.println("solid color orange");
    fill_solid(leds, NUM_LEDS, CRGB(0,255,45));//sahi value h
     FastLED.show();
}

void solid_colour_purple()
{    Serial.println("solid color purple");
    fill_solid(leds, NUM_LEDS, CRGB(128,128,0));//sahi value h
     FastLED.show();
}
void solid_colour_pink()
{    Serial.println("solid color pink");
    fill_solid(leds, NUM_LEDS, CRGB(50,255,20));//sahi value h
     FastLED.show();//(255,0,255)
}
void solid_colour_ocean()
{    Serial.println("solid color ocean");
    fill_solid(leds, NUM_LEDS, CRGB(255,0,255));//sahi value h
     FastLED.show();//
}
//----------------------------------------------------------------------------------------------------

//////////////////////
void running_tail_redc() 
{ int c=0;
  Serial.println("running tail red");
  for ( int c = 0; c<=NUM_LEDS; c++)
  {
    leds[c]=CRGB( 0,255,0);
    FastLED.show(); 
  delay(50);
  fadeall();
  }}
  
void running_tail_blue() 
{ int c=0;
  Serial.println("running tail blue");
  for ( int c = 0; c<=NUM_LEDS; c++)
  {
    leds[c]=CRGB( 255,0,0);
    FastLED.show(); 
  delay(50);
  fadeall();
  }}
  
void running_tail_green() 
{ 
  int c=0;
  Serial.println("running tail green");
  for ( int c = 0; c<=NUM_LEDS; c++)
  {
    leds[c]=CRGB( 0,0,255);
    FastLED.show();
    delay(50); 
    fadeall();
  }
}

  
 void running_tail_yellow() 
{ int c = 0;
  Serial.println("running tail yellow");
  for ( int c = 0; c<=NUM_LEDS; c++)
  {
    leds[c]=CRGB(0,210,60);
    FastLED.show(); 
  delay(50);
  fadeall();
  }}

void running_tail_orange() 
{ 
  int c = 0;
  Serial.println("running tail orange");
  for ( int c = 0; c<=NUM_LEDS; c++)
  {
    leds[c]=CRGB(0,255,45);
    FastLED.show();
    delay(50); 
  fadeall();
  }
}
void running_tail_purple()
{
      int c = 0;
    Serial.println("running tail purple");
    for ( int c = 0; c<=NUM_LEDS; c++)
    {
      leds[c]=CRGB(128,128,0);
      FastLED.show();
      delay(50); 
      fadeall();
    }
}
void running_tail_pink()
{
      int c = 0;
    Serial.println("running tail pink");
    for ( int c = 0; c<=NUM_LEDS; c++)
    {
      leds[c]=CRGB(50,255,20);
      FastLED.show();
      delay(50); 
      fadeall();
    }
}
void running_tail_ocean()
{
      int c = 0;
    Serial.println("running tail ocean");
    for ( int c = 0; c<=NUM_LEDS; c++)
    {
      leds[c]=CRGB(255,0,255);//(255,0,255)
      FastLED.show();
      delay(50); 
      fadeall();
    }
}
void fadeall() 
{ 
    int v=0;
  for(int v = 0; v < NUM_LEDS; v++) 
  { 
    //Serial.println(i);
    leds[v].nscale8(TRAIL); 
  } 
}
//-------------------------------------****--------------------------------------------------------------------
void wave_red()
{     
  Serial.println("wave red");
      int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(0,255,0));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          Serial.println(i); 
      }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          Serial.println(i);
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(0,255,0));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            Serial.println(i);
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          Serial.println(i);
     }
}

/////////////////////
void wave_blue()
{     Serial.println("wave blue");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(255,0,0));
          controllers[i]->showLeds(gBrightness);
          delay(d);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(d);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(255,0,0));
            controllers[i]->showLeds(gBrightness);
            delay(d);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(d);
          
     }
}

///////////////////////////////
void wave_green()
{     Serial.println("wave green");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(0,0,255));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(0,0,255));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}
///////////////////////////////////
void wave_yellow()
{     Serial.println("wave yellow");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(0,210,60));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(0,210,60));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}
///////////////////////////////////////////
void wave_orange()
{     Serial.println("wave orange");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(0,255,45));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(0,255,45));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}

void wave_purple()
{     Serial.println("wave purple");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(128,128,0));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(128,128,0));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}
void wave_pink()
{     Serial.println("wave pink");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(50,255,20));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(50,255,20));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}
void wave_ocean()
{     Serial.println("wave ocean");
        int i=0;
      for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(255,0,255));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          //Serial.println(i);
          
     }
     for(i=initial_value; i<=final_value; i++)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
     
     }
      for(i=final_value; i>=initial_value; i--)
       {
            
            fill_solid(leds, NUM_LEDS,CRGB(255,0,255));
            controllers[i]->showLeds(gBrightness);
            delay(100);
            
       }
     for(i=final_value; i>=initial_value; i--)
      {
          fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green));
          controllers[i]->showLeds(gBrightness);
          delay(100);
          
     }
}
//------------------------------------------***************************-----------------------------------------
void blink_one_by_one_red()
{ Serial.println("blink red");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {         //Serial.println(i);
            fill_solid(leds, NUM_LEDS,CRGB(0,255,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {         //Serial.println(i);
            fill_solid(leds, NUM_LEDS,CRGB(0,255,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
///////////////////////
void blink_one_by_one_blue()
{ Serial.println("blink blue");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(255,0,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(255,0,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
////////////
void blink_one_by_one_green()
{ Serial.println("blink green");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(0,0,255));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(0,0,255));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
//////////////
void blink_one_by_one_yellow()
{ Serial.println("blink yellow");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {//(b,r,g)(0,255,255)
            fill_solid(leds, NUM_LEDS,CRGB(0,210,60));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(0,210,60));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
//////////////////////////
void blink_one_by_one_orange()
{ Serial.println("blink orange");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(0,255,45));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(0,255,45));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}

void blink_one_by_one_purple()
{ Serial.println("blink purple");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(128,128,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(128,128,0));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
void blink_one_by_one_pink()
{ Serial.println("blink pink");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(50,255,20));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(50,255,20));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
void blink_one_by_one_ocean()
{ 
  Serial.println("blink ocean");
  int d=100;
  int i=0;
  for(i=initial_value;i<=final_value;i++)//turn on and off led one by one from left to right
  {
            fill_solid(leds, NUM_LEDS,CRGB(255,0,255));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }
  for(i=final_value;i>=initial_value;i--)//turn on and off led one by one from right to left
  {
            fill_solid(leds, NUM_LEDS,CRGB(255,0,255));//this will turn on the strip once
            controllers[i]->showLeds(gBrightness);
            delay(d);

            fill_solid(leds, NUM_LEDS, CRGB(g_red,g_blue,g_green)); //this will turn of that strip and then shift to next strip
            controllers[i]->showLeds(gBrightness);
  }         
}
