// Pinos referentes aos LEDs do semáforo para carros
const int VERMELHO = 4;
const int AMARELO = 5;
const int VERDE = 6;

// Pinos referentes aos LEDs do semáforo para pedestres
const int VERMELHO_PEDESTRE = 9;
const int VERDE_PEDESTRE = 10;

// Tempo de duração dos sinais semafóricos para carros
const int TEMPO_VERMELHO = 8000;
const int TEMPO_AMARELO = 3000;
const int TEMPO_VERDE = 10000;

// Alerta de fechamento do semáforo para pedestres
const int DELAY = 500;
const int PISCADAS = 3;

void semaforoCarros(int estadoRed, int estadoYellow, int estadoGreen) {
  digitalWrite(VERMELHO, estadoRed);
  digitalWrite(AMARELO, estadoYellow);
  digitalWrite(VERDE, estadoGreen);
}

void semaforoPedestre(int estadoRed, int estadoGreen) {
  digitalWrite(VERMELHO_PEDESTRE, estadoRed);
  digitalWrite(VERDE_PEDESTRE, estadoGreen);
}

void alertaFechamento() {
  digitalWrite(VERDE_PEDESTRE, LOW);

  digitalWrite(VERMELHO_PEDESTRE, HIGH);
  delay(DELAY);
  digitalWrite(VERMELHO_PEDESTRE, LOW);
  delay(DELAY);
}

void setup() {
  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(VERMELHO_PEDESTRE, OUTPUT);
  pinMode(VERDE_PEDESTRE, OUTPUT);
}

void loop() {
  // Semáforo fechado para os pedestres e aberto para os carros
  semaforoCarros(LOW, LOW, HIGH);
  semaforoPedestre(HIGH, LOW);
  delay(TEMPO_VERDE);

  // Semáforo continua fechado para os pedestres e aberto para os carros
  semaforoCarros(LOW, HIGH, LOW);
  semaforoPedestre(HIGH, LOW);
  delay(TEMPO_AMARELO);

  // Semáforo fechado para os carros e aberto para os pedestres
  semaforoCarros(HIGH, LOW, LOW);
  semaforoPedestre(LOW, HIGH);
  delay(TEMPO_VERMELHO);
  
  // Faz o sinal vermelho para o pedestre piscar como alerta
  for(int i = 0; i < PISCADAS; i++) {
    alertaFechamento();
  }

}
