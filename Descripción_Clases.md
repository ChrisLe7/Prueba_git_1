# Descripción de las Clases:

## Clase: Paciente.
**Descripción de la clase:** 
Esta clase contiene la información de un paciente de la consulta médica, además de los métodos que se podrán realizar ya sea su historial médico , sus tratamientos o su cita.

**Datos:**
*	**Nombre Completo:** string 
*	**Edad:** int
*	**Telefono:** double
*	**Peso:** float
*	**Altura:** float
*	**Citas:** list < Cita >
* **Tratamientos** : list < Tratamiento >

**Métodos:**
*	**Modificar_datos_paciente:**         Solicita los campos que se desean modificar del paciente y solicita los nuevos campos . Posteriormente actualiza los datos del paciente.
* 	**Concertar_cita:**         Función que concerta una cita libre para un paciente.
* 	**Cancelar_cita:**        Función que elimina una cita de un paciente, liberandola de la agenda.
* 	**Cambiar_cita:**        Función que modifica una cita actual de un paciente por otra cita libre. Dejando como libre la cita inicial del paciente.
*	**Mostrar_tratamiento:**        Muestra el tratamiento de un paciente. Siguiendo el siguiente formato:        Receta, fecha de inicio, fecha de finalización.
*	**Añadir_tratamiento:**            Solicita los datos de un nuevo tratamiento y los asigna a un paciente.
*	**Finalizar_tratamiento :**         Finaliza un tratamiento vigente. Cancelando y modificando la fecha de finalización.
*   **Mostrar_historial_medico :**            Función que muestra el historial del paciente.
*   **Añadir_historial_medico:**             Solicita el nuevo historial medico para un paciente.
## Clase: Cita.

**Descripción de la clase:**
Esta clase contiene los campos destinados para la gestión de una cita.

**Datos:** 
*	**Fecha:** string
*	**Hora:** string            
*	**Paciente:** string .        Nombre del paciente que concerta la cita

**Métodos:**
*	**Consultar_cita** : 	Comprueba si una cita esta reservada o esta libre para reservarla. 

## Clase: Tratamiento.

**Descripción de la clase:** Esta clase contiene los campos destinados para los tratamientos de un paciente.

**Datos:** 
* **fecha de inicio:** string        
* **fecha de finalización:** string    
* **Receta:** string            Almacena la dosis, el medicamento y los motivos de la consulta.



## Clase: Historial Medico.

**Descripción de la clase:** Esta clase contiene los campos destinados para el historial de un paciente.

**Datos**: 
*	**fecha:** string
*	**motivo:** string



