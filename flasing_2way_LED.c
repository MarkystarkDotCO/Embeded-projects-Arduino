int led1=5;
int led2=6;
int Direction=0;
int freq = 100;
void setup() {
  for(int i=2; i<10; i++){
     pinMode(i, OUTPUT);
     digitalWrite(i,LOW);
    }
}

void loop() {

    if(led1>2 && Direction==0){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(freq);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(freq);
    led1--;
    led2++;
    freq = freq*0.6;
    if(led1==2)Direction=1;
    }
   
    if(led1>=2 && Direction==1){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(freq);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(freq);
    led1++;
    led2--;
    freq = freq*0.6;
    if(led1==5){
      Direction=0;
      freq = 100;
      }
    }

  
}
