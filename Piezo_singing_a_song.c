// เพลง คีย์ Dm
// A Bb C D E F G
#define none 0

#define A3 220.00
#define Bb3 233.08


#define F3 174.61
#define G3 196.00

#define A4 440.00
#define Bb4 466.16
#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00

#define C5 523.25
#define D5 587.33
#define F5 698.46

 
float melody[]   = {A4, none, A4, none, A4, none, A4, none, A4, none, A4,  none, C5, none,  F4,  G4,   F4,  F4,  none,
                    D4, none, D4, none, D4, none, D5, none, D5, none, none, D5,  none, D5, none, D5,  none, F5,  none, D5,  none,
                    A3, none, D4, none, C4, none, G3, none, C4, none, Bb3, none,  A3, none, F3, none,  G3, none,
                    F4, none, F4, none, F4, none ,F4, none, D4, none, C4,  none,  F4, none, F4, none,  F4, none , F4, none, G4, none, G4, none, A4, none,
                    F4, none, F4, none, F4, none ,F4, none, D4, none, C4,  none,  F4, none, F4, none,  F4, none , F4, none, A4, none, G4, none, F4, none,
                    C4, none, C4, none, C4, none ,C4, none, Bb4,none, A4,  none,  Bb4,none, C4, none,
                    C4, none, D4, none, F4, none, F4, none, A4, none, G4,  none,  F4, none, G4, none, 
                    C4, none, D4, none, F4, none, D4, none, F4, none, A4,  none,  G4, none, F4, none, G4,  none,
                    A4, none, C5, none, A4, none, G4, none, F4, none, D4,  none,  D4, none, C4, none, A3,  none,  F4, none, F4, none, 
                    C4, none, Bb3,none,A3, none, G3 ,none, A3 ,none, Bb4, none,  D4, none, A4, none, C4,  none,  D4, none, F4,none,
                    C4, none, D4, none, A4,
                   };
float duration[] = {200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   200, 70,  200, 70,  200, 70,  200, 
                    200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   200, 70,  200, 70,  200, 70,  200, 70, 200,
                    200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   200, 70,  200, 70,  200, 70,
                    200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200, 70, 
                    200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200, 1000,
                    200, 70,  200, 70,  200, 70,  200, 70,  300, 70,  300,  70,   300, 70,
                    200, 70,  200, 70,  300, 70,  700, 70,  300, 70,  300,  70,   300, 70,
                    200, 70,  200, 70,  200, 70,  200, 70,  700, 70,  200,  70,   200, 70,  200, 70,   500, 70,
                    200, 70,  200, 70,  200, 70,  200, 70,  300, 70,  300,  70,   200, 70,  200, 70,   200, 70,  200, 70,  200, 70, 
                    200, 70,  200, 70,  200, 70,  200, 70,  200, 70,  200,  70,   500, 70,  300, 70,   300, 70,  300, 70,  400, 70,
                    300, 70,  300, 70,  500,
                   };
int songLength = sizeof(melody)/sizeof(melody[0]);

int buzzer = 8;



// register 1
int latchPin1 = 11;      
int clockPin1 = 9;      
int dataPin1 = 12;     

// register 2
int latchPin2 = 5;      
int clockPin2 = 4;    
int dataPin2 = 6;    

byte dataRED;

byte dataArrayRED[10];

int digit = 0;
int number=0;

const int buttonPin1 = 13;
int buttonState1 = 0; 

const int buttonPin2 = 7;
int buttonState2 = 0;

const int buttonPin3 = 3;
int buttonState3 = 0;


void setup() 
{
   pinMode(buzzer, OUTPUT);
  // register 1 settingup
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);  
  pinMode(clockPin1, OUTPUT);
  
  // register 2 settingup
  
  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);  
  pinMode(clockPin2, OUTPUT);
  
  //Bit to display led number
dataArrayRED[0] = 0x3F; //A

dataArrayRED[1] = 0x06; //Bb

dataArrayRED[2] = 0xDB; //C

dataArrayRED[3] = 0x4F; //D

dataArrayRED[4] = 0x66; //F

dataArrayRED[5] = 0x6D; //G

dataArrayRED[6] = 0x7D; 

dataArrayRED[7] = 0x07; 

dataArrayRED[8] = 0xFF; 

dataArrayRED[9] = 0x6F; 
 
}

void loop() 
{
  
  for(int i=0; i<songLength; i++){
    
    
    if(melody[i]==0){
    noTone(buzzer);     // Stop sound...
    display_number(0);
    delay(duration[i]);    
    }
    else{
      if(melody[i]==220.00 || melody[i]==440.00){display_number(1);}//A
      else if(melody[i]==233.08 || melody[i]==466.16){display_number(2);}//Bb
      else if(melody[i]==261.63 || melody[i]==523.25){display_number(3);}//C
      else if(melody[i]==293.66 || melody[i]==587.33){display_number(3);}//D
      else if(melody[i]==329.63){display_number(3);}//E
      else if(melody[i]==174.61 || melody[i]==349.23 || melody[i]==698.46){display_number(3);}//F
      else if(melody[i]==196.00 || melody[i]==392.00){display_number(3);}
      
    tone(buzzer, melody[i]);
    delay(duration[i]);
    }
  
  }
  
 
}


// display number in led1
void led1_brigth(int i){
  bitSet(dataArrayRED[i], 8);
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin1, HIGH);
  
  bitClear(dataArrayRED[i], 8);
  digitalWrite(latchPin1, HIGH);
  shiftOut(dataPin1, clockPin1, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin1, LOW);
}

// display number in led2
void led2_brigth(int i){
  bitSet(dataArrayRED[i], 8);
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin2, HIGH);
  
  bitClear(dataArrayRED[i], 8);
  digitalWrite(latchPin2, HIGH);
  shiftOut(dataPin2, clockPin2, MSBFIRST, dataArrayRED[i]); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
  digitalWrite(latchPin2, LOW);

}
