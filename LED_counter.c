int Number = 0;
int buttonState=0;
int getInput = 2;

void setup()
{
  pinMode(getInput, INPUT);
  for(int i=13; i>6; i--){
   pinMode(i, OUTPUT);
  }
}
void loop()
{
  buttonState = digitalRead(getInput);
   
  if(buttonState==1 && Number <9){
  led_print(Number++);
    delay(200);
  }
  
  else if(buttonState==1 && Number ==9){
  Number=0;
  led_print(Number);
  delay(200);
  }
  
  else{
    led_print(Number);
    delay(50);
  }
  
}
//หลอดแบบ Anode
 //ถ้ามีไฟเข้า(HIGH) หลอดไฟนั้นจะดับ
void led_print(int i){
  
  if(i==1){

   digitalWrite(13, HIGH); //A
   digitalWrite(12, HIGH); //F
   digitalWrite(11, HIGH); //G
   digitalWrite(9, HIGH); //E
   digitalWrite(8, HIGH); //D
   
    
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
  }
  
  else if(i==2){
   digitalWrite(7, HIGH); 
   digitalWrite(12, HIGH);  
    
    digitalWrite(13, LOW); 
     digitalWrite(10, LOW); 
     digitalWrite(8, LOW); 
  
     digitalWrite(9, LOW); 
     digitalWrite(11, LOW); 
  }
  
  else if(i==3){
   digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
    
     digitalWrite(13, LOW); 
     digitalWrite(10, LOW); 
     digitalWrite(8, LOW); 
      digitalWrite(6, LOW);
     digitalWrite(7, LOW); 
     digitalWrite(11, LOW); 
    
  }
  
  else if(i==4){
  digitalWrite(13, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    
     digitalWrite(12, LOW); 
     digitalWrite(10, LOW); 
      
     digitalWrite(7, LOW); 
     digitalWrite(11, LOW);
  }
  
  else if(i==5){
  digitalWrite(10, HIGH); 
  digitalWrite(9, HIGH);
  
       
    digitalWrite(13, LOW); 
   
     digitalWrite(8, LOW); 
   
      digitalWrite(7, LOW);
   
     digitalWrite(11, LOW); 
     digitalWrite(12, LOW); 
  
  }
  else if(i==6){ 
    digitalWrite(10, HIGH);
    
    
     digitalWrite(13, LOW); 
     digitalWrite(12, LOW); 
      digitalWrite(11, LOW);
     digitalWrite(9, LOW); 
     digitalWrite(8, LOW); 
    digitalWrite(7 ,LOW); 
  }
  
  else if(i==7){
   digitalWrite(12, HIGH); 
   digitalWrite(11, HIGH); 
   digitalWrite(9, HIGH); 
   digitalWrite(8, HIGH); 
    
     digitalWrite(13, LOW); 
     digitalWrite(10, LOW); 
     digitalWrite(7, LOW); 
    
  }
  
  else if(i==8){
  
     digitalWrite(13, LOW); 
     digitalWrite(12, LOW); 
      digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW); 
     digitalWrite(8, LOW); 
    digitalWrite(7 ,LOW); 
  }
  
  else if(i==9){digitalWrite(9, HIGH); 
                
     digitalWrite(13, LOW); 
     digitalWrite(12, LOW); 
      digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(8, LOW); 
    digitalWrite(7 ,LOW); 
  }
  
  else if(i==0){
  digitalWrite(11, HIGH); 
    
    
     digitalWrite(13, LOW); 
     digitalWrite(12, LOW); 
     digitalWrite(10, LOW);
     digitalWrite(9, LOW); 
     digitalWrite(8, LOW); 
    digitalWrite(7 ,LOW); 
  }
}
