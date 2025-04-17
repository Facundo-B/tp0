#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char *ip;
	char *puerto;
	char *valor;

	t_log *logger;
	t_config *config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	logger = log_create("./tp0.log", "client", 1, LOG_LEVEL_INFO);

	log_info(logger, "Hola, soy un log jua jua :)");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	config = config_create("./cliente.config");

	if (config != NULL)
	{

		// Loggeamos el valor de config

		valor = config_get_string_value(config, "CLAVE");
		ip = config_get_string_value(config, "IP");
		puerto = config_get_string_value(config, "PUERTO");
		char *config_value = string_from_format("El valor es: %s", valor);
		char *config_ip = string_from_format("La IP es: %s", ip);
		char *config_port = string_from_format("El puerto es: %s", puerto);
		log_info(logger, config_value);
		log_info(logger, config_ip);
		log_info(logger, config_port);
		free(config_value);
		free(config_ip);
		free(config_port);
	}
	else
	{
		abort();
	}

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	// paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log *iniciar_logger(void)
{
	t_log *nuevo_logger;

	return nuevo_logger;
}

t_config *iniciar_config(void)
{
	t_config *nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log *logger)
{
	char *leido;

	// La primera te la dejo de yapa
	// leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while (true)
	{
		leido = readline("> ");
		if (strcmp(leido, "") != 0)
		{
			log_info(logger, leido);
			free(leido);
		}
		else
		{
			log_(logger, "Cerrando...");
			break;
		}
	}
	// ¡No te olvides de liberar las lineas antes de regresar!
	free(leido);
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char *leido;
	t_paquete *paquete;

	// Leemos y esta vez agregamos las lineas al paquete

	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
}

void terminar_programa(int conexion, t_log *logger, t_config *config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config)
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	log_destroy(logger);
	config_destroy(config);
}
