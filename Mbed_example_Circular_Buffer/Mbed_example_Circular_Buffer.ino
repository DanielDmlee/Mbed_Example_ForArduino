#include <mbed.h>

using namespace mbed;

#define BUF_SIZE    10


CircularBuffer<char, BUF_SIZE> buf;
char data_stream[] = "DataToBeAddedToBuffer";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    uint32_t bytes_written = 0;
    
    while (!buf.full()) {
        buf.push(data_stream[bytes_written++]);
    }
    Serial.println("============== Example start ==============");
    Serial.print("Is the buffer empty? ");
    Serial.println(buf.empty());
    Serial.print("Is the buffer full? ");
    Serial.println(buf.full());
    Serial.print("Bytes written ");
    Serial.println(bytes_written);
    
    // If buffer is full, contents will be over-written
    buf.push(data_stream[bytes_written++]);

     char data;
    Serial.println ("Buffer contents: ");
    while (!buf.empty()) {
        buf.pop(data);
        Serial.println(data);
        wait_ms(100);
    }
 
    Serial.print("Is the buffer empty? ");
    Serial.println(buf.empty());
    Serial.print("Is the buffer full? ");
    Serial.println(buf.full());
    Serial.println("============== Example end ==============");
    wait(5);
}
