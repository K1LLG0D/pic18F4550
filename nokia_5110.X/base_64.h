
#include <string.h> // strncpy

#define LONGITUD_LINEA 76
#define MASCARA_B64 0B00111111
#define ULTIMO_CODIGO_BASE64 64 // 64 caracteres más el signo igual (empezando a contar desde cero)
#define MAXIMA_LONGITUD_RESULTADO 6 // Máximo número de caracteres del resultado parcial de la codificación. Puede ser 1 si no se ha llegado al final de un bloque (2 bytes en el original, 4 en la conversión), 2 si se ha llegado al final de un bloque, 3 si no se ha llegado al final de un bloque pero se supera la longitud máxima de la línea, 4 si se llega al final de un bloque y se supera la longitud máxima de la línea, 5 si hay que rellenar con un signo igual o 6  si hay que rellenar con dos signos igual

class Base64
{
  private:
    unsigned char simbolo_base64[ULTIMO_CODIGO_BASE64+1]; // Espacio para la codificación Base64, el relleno (=) una terminación en \0
    unsigned int numero_valor; // Posición (empezando en cero) que ocupa el valor que se desea convertir en el mensaje completo original
    unsigned int numero_codigo; // Posición del último código calculado. Podría limitarse al ancho de la línea (LONGITUD_LINEA, 76 caracteres) pero usando un contenedor alto se podría implementar también una cuenta estadística
    unsigned char resto_base64; // �?ltimo resto obtenido al calcular el último código
    unsigned char resultado[MAXIMA_LONGITUD_RESULTADO+1]; // Resultado de la conversión actual. Si es terminal puede incluir el caracter 65 (=) una o dos veces
    unsigned char contador_caracteres_resultado=0;
    void acumular_resultado(unsigned char valor);
  public:
    Base64();
    ~Base64();
    void iniciar_conversion();
    unsigned char *convertir(unsigned char valor_original, bool terminar_conversion);
    unsigned char *convertir(unsigned char valor_original);
    unsigned char *terminar();
};
