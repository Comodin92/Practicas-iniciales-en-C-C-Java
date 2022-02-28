/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hola.mundo;
import java.util.Scanner; //importamos Scanner, para las entradas

/**
 *
 * @author Agus
 */

public class HolaMundo { //Mi clase Principal


    public static void main(String[] args) //El main dentro de mi clase
    {
        //------------------------Salida por pantalla--------------------------//

        //printf("Hola Mundo");
        //System.out.println("Hola mundo");

//        int _variable = 5, 
//            $variable = 3, 
//            resultado = _variable + $variable;
//
//        boolean variable4 = true; //Tipo de dato booleano
//
//        // \b <- retroceso (sirve para cadenas)
//
//        System.out.println("Mi variable tiene el valor: " + _variable );
//        System.out.println("\tEl resultado de sumar  \b" + _variable + " y " + $variable + " es " + resultado);

        //------------------------Ejercicio 1---------------------------------//

//        String cad = "Karla",
//               cad2 = "Esparza";
//
//        System.out.println("Concatenacion: " + cad + cad2);      
//        System.out.println("Nueva Linea: \n" + cad + " " + cad2);
//        System.out.println("Tabulador: \t" + cad + " " + cad2);
//        System.out.println("Retroceso: \b\b" + cad + " " + cad2 + "\n" + cad + " " + cad2);
//        System.out.println("Comillas simple: '" + cad + " " + cad2 + "'");
//        System.out.println("Comillas dobles: \"" + cad + " " + cad2 + "\"");

        //--------------------Ingreso por entrada-----------------------------//

//        System.out.print("Ingresa Nombre: ");
//        Scanner entrada = new Scanner(System.in);
//        String nombre = entrada.nextLine();
//        System.out.print("Ingrese Apellido: ");
//        String apellido = entrada.nextLine();
//        System.out.print("Ingrese edad: ");
//        int edad = entrada.nextInt();
//        
//        System.out.println("El Nombre es: " + nombre);
//        System.out.println("El Apellido es: " + apellido);
//        System.out.println("La edad es: " + edad);

        //------------------------Ejercicio 2---------------------------------//

//        System.out.print("Ingresa cantidad de hojas del libro: ");
//        Scanner ingreso = new Scanner(System.in);
//        String cantidad = ingreso.nextLine();
//        int cantHojas = Integer.parseInt(cantidad);
//
//        System.out.print("Ingresa el titulo del libro: ");
//        String titulo = ingreso.nextLine();
//
//        System.out.print("Ingresa el nombre del autor: ");
//        String autor = ingreso.nextLine();
//
//        System.out.println("Cantidad de hojas: " + cantHojas);
//        System.out.println("Titulo: " + titulo);
//        System.out.println("Autor: " + autor);
//
//        System.out.println("\n" + titulo + " fue escrito por " + autor + " y tiene " + cantHojas + " hojas");

        //---------------------Casteos de datos-------------------------------//
       
//        int num;
//        double num2; 
//        String cad = "70";
//        
//        num = Integer.parseInt(cad); //casteo el string 79 a entero
//        num2 = Double.parseDouble(cad); //casteo el string 79 a double
//
//        System.out.println("Dato en (String) = " + cad);
//        System.out.println("Dato de (String) a (int) = " + num);
//        System.out.println("Dato de (String) a (double) = " + num2);

        //------------------------Ejercicio 3---------------------------------//

//        //Ingresos
//        Scanner ingreso = new Scanner(System.in);
//
//        System.out.print("Nombre del libro: ");
//        String nombre = ingreso.nextLine();
//
//        System.out.print("ID: ");
//        int id = Integer.parseInt(ingreso.nextLine());
//        
//        System.out.print("Precio: ");
//        double precio = Double.parseDouble(ingreso.nextLine());
//
//        System.out.print("Envio gratuito (true o false): ");
//        boolean envio = Boolean.parseBoolean(ingreso.nextLine());
//
//        //Salidas
//        System.out.println("\n\n" + nombre + "\t#"+ id);
//        System.out.println("Precio: $" + String.format("%.2f", precio)); //String format, para añadir decimales 
//        System.out.println("Envio gratuito: " + envio);

        //-----------------------Bucles Switch--------------------------------//
        
//        int varible1 = 7,
//            varible2 = 5,
//            i;
//            
//        //Condiciones 
//        if(variable1 > variable2) // != == && || <= >= < >
//        {
//            System.out.println("La variable 1 es mayor que la variable 2");
//            variable1++;
//        }
//
//        else System.out.println("La variable 2 es mayor que la variable 1");
//
//        //While
//        while(variable != 0)
//        {
//            System.out.println(variable1);
//            variable1--;
//        }
//
//        //For
//        for(i = 0; i<10; i++, variable++)
//        {
//            if(variable == 14)
//                break; //Salida forzada 
//            System.out.println("variable1: " + variable1);
//        }
//        System.out.println("Fin");
//
//        //Switch
//        switch(variable1)
//        {
//            case 1:
//                    System.out.println("Caso 1");
//                    break;
//            case 7:
//                    System.out.println("Caso 7");
//                    break;
//            default:
//                    System.out.println("Caso inexistente");
//                    break;
//        }

        //------------------------Ejercicio 4---------------------------------//

        Scanner entrada = new Scanner(System.in);
        System.out.print("Ingresa un numero entero: ");
        int num = entrada.nextInt();

        if((num % 2) == 0)
            System.out.println("El numero " + num + " es PAR");

        else System.out.println("El numero " + num + " no es PAR");

    }
}
