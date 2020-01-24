#define BUFF_SIZE 8

using namespace rtos;

Mutex stdio_mutex;
Thread t2;
Thread t3;

void print_message(const char* name, int state) {
    stdio_mutex.lock();
    Serial.printf("%s: %d\n\r", name, state);
    stdio_mutex.unlock();
}

void test_thread(void const *args) {
  while (true) {
    print_message((const char*)args, 0); 
    wait(1);
    print_message((const char*)args, 1);
    wait(1);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  t2.start(mbed::callback(test_thread, (void *)"Th 2"));
  t3.start(mbed::callback(test_thread, (void *)"Th 3"));
}

void loop()
{ 
    Serial.print("+");
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    wait_ms(500);  
    Serial.print("-");
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    wait_ms(500);                       // wait for a second
}
