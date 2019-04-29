int DonmeHizi = 175;
const int sagileri = 9;
const int saggeri = 8;
const int solileri = 12;
const int solgeri = 13;
const int solenable = 11;
const int sagenable = 10;

void ileri(int hiz){
  
  analogWrite(sagenable, hiz); 
  digitalWrite(sagileri,HIGH); 
  digitalWrite(saggeri,LOW); 

  analogWrite(solenable, hiz); 
  digitalWrite(solileri, HIGH); 
  digitalWrite(solgeri,LOW);
}

void sagaDon(int hiz){
  analogWrite(sagenable, hiz); 
  digitalWrite(sagileri,LOW); 
  digitalWrite(saggeri,HIGH); 

  analogWrite(solenable, hiz); 
  digitalWrite(solileri, HIGH); 
  digitalWrite(solgeri,LOW); 
}

void solaDon(int hiz){
  analogWrite(sagenable, hiz); 
  digitalWrite(sagileri,HIGH);
  digitalWrite(saggeri,LOW); 

  analogWrite(solenable, hiz); 
  digitalWrite(solileri, LOW); 
  digitalWrite(solgeri,HIGH); 
}

void geri(int hiz){
  analogWrite(sagenable, hiz); 
  digitalWrite(sagileri,LOW); 
  digitalWrite(saggeri, HIGH); 

  analogWrite(solenable, hiz);
  digitalWrite(solileri, LOW);/
  digitalWrite(solgeri, HIGH);
}

void dur()
{
  
  digitalWrite(sagileri, HIGH);
  digitalWrite(saggeri, HIGH);
  digitalWrite(solileri, HIGH);
  digitalWrite(solgeri, HIGH);
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
