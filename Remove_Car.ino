char val;
#define in1 10
#define in2 11
#define in3 12
#define in4 13

void setup() {
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

}
void loop() {

  if (Serial.available()){
    val = Serial.read();
  }

  if(val=='F'){
    digitalWrite(in2,HIGH);
    digitalWrite(in4,HIGH);

    digitalWrite(in1,LOW);
    digitalWrite(in3,LOW);
  }

  else if(val=='B'){
    digitalWrite(in2,LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in1,HIGH);
    digitalWrite(in3,HIGH);
  }

  if(val=='L'){
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    digitalWrite(in4,1);
    digitalWrite(in3,0);
  }

  if(val=='R'){
    digitalWrite(in2,1);
    digitalWrite(in1,0);
    digitalWrite(in3,0);
    digitalWrite(in4,0);


  }
  if(val == 'S'){
    digitalWrite(in1,0);
    digitalWrite(in2,0);
    digitalWrite(in3,0);
    digitalWrite(in4,0);
  }
               
 

}