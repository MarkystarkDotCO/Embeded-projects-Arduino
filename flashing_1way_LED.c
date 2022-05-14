int direction = 0;
int LED = 13;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  if(direction==0){
    digitalWrite(LED, HIGH);
    digitalWrite(LED - 1, LOW);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(LED, LOW);
    digitalWrite(LED - 1, HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    if(LED-1==6){
      direction=1;
      digitalWrite(LED - 1, LOW);
      delay(100); // Wait for 1000 millisecond(s)
    }
    else{
      LED = LED - 1;
    }
  }
  
  if(direction==1){
    digitalWrite(LED, HIGH);
    digitalWrite(LED + 1, LOW);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(LED, LOW);
    digitalWrite(LED + 1, HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    if(LED+1==13){
      direction=0;
      digitalWrite(LED + 1, LOW);
      delay(100); // Wait for 1000 millisecond(s)
    }
    else{
      LED = LED + 1;
    }
  
  }
  
}
