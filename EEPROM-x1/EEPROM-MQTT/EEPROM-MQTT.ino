#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <EEPROM.h>

const char* ssid = "Springfield";            // WiFi SSID
const char* password = "siscxrisc1";        // WiFi Password
const char* mqtt_server = "tailor.cloudmqtt.com";  // IP Broker MQTT

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
int j, k;


void setup()
{
   Serial.begin(9600);//Inicia a comunicação Serial.

   setup_wifi();
   client.setServer(mqtt_server, 12415);
   client.setCallback(callback);

   EEPROM.begin(4);//Inicia a EEPROM com tamanho de 4 Bytes (minimo).
   
}


void loop()
{
  /*
  Serial.println(EEPROM.read(0));//Mostra no Monitor oque há antes de efetuar a gravação
   if (EEPROM.read(0) != 18)//Se não existir o numero escolhido (18), irá gravar. Isto é necessário para evitar regravações desnecessárias.
   {
      EEPROM.write(0, 18);//Escreve no endereço "0", o valor "18".
      EEPROM.commit();//Salva o dado na EEPROM.
      Serial.println(EEPROM.read(0));//Mostra o valor no endereço 0 novamente.
   }
   else//Se já existir o valor, irá avisar.
   {
      Serial.println("Dado ja cadastrado");
   }
   EEPROM.end();//Fecha a EEPROM.
    */
   char msg[5];
  
  if (!client.connected()) {
    reconnect();
  }

  itoa(EEPROM.read(0),msg,10);
   client.publish("Teste/ver-EEPROM", msg);
      
  client.loop();
  delay(100);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  
 String string;
 char Servomsg[5];
 
 Serial.print("Messagem Recebida: [");
 Serial.print(topic);
 Serial.print("] ");
 String topico = String((char*)topic);
 Serial.println(topico);

 if(topico=="Teste/EEPROM"){
    
     for (int i = 0; i < length; i++) {
        string+=((char)payload[i]); 
     }

      int valor = string.toInt();
      
      EEPROM.write(0, valor);
      EEPROM.commit();
 
    }
}

void reconnect() {
  
  while (!client.connected()) {
    Serial.print("Aguardando conexao ao MQTT...");
    
    if (client.connect("ESP8266Client","bevcctrk","eXGg885Wmm_I")) {
      Serial.println("Conectado");
      client.subscribe("Teste/EEPROM");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      
      delay(5000);
    }
  }
}
