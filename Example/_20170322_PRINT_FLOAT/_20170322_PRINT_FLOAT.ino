#include <avr/io.h>
#include <stdio.h>

void usart_putchar(char data);
int usart_putchar_printf(char var, FILE *stream);
static FILE mystdout; /* FDEV_SETUP_STREAM(usart_putchar_printf, NULL,
_FDEV_SETUP_WRITE); */
void usart_putchar(char data) {
  // Wait for empty transmit buffer
  while ( !( UCSR0A & (1 << UDRE0)) ) ;
  // Put data into buffer, sends the data
  UDR0 = (unsigned char)data;
}

// this function is called by printf as a stream handler
int usart_putchar_printf(char var, FILE *stream) {
  // translate \n to \r for br@y++ terminal
  if (var == '\n') usart_putchar('\r');
  usart_putchar(var);
  return 0;
}

void retarget_stdio(void) {
  // setup our stdio stream
  mystdout.put = usart_putchar_printf;
  mystdout.get = NULL;
  mystdout.flags = _FDEV_SETUP_WRITE;
  mystdout.udata = 0;
  stdout = &mystdout;
}

void setup(void) {
  Serial.begin(9600);
  retarget_stdio();
  puts("*** START ***");
}

void loop(void) {
  static uint32_t count = 0;
  static float realnum = 0.23;
  printf("count = %04u\r\n", count);
  printf("real number = %4.2f\r\n", realnum);
  char str_temp[7];
  dtostrf(realnum, 4, 2, str_temp);
  printf("real number = %s\r\n\r\n", str_temp);
  count++;
  realnum += 1.47;
  delay(1000);
}
// printf 함수가 실수 표현을 정상 출력하지 못하므로,
// 실수를 출력할 때는 dtostrf 함수를 대신 사용해야 함
