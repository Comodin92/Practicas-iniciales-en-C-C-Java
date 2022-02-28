/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aritmetica;

/**
 *
 * @author Agus
 */
public class Aritmetica {

    
    int a,
        b;
    
    Aritmetica() {} //Constructor x defecto
    
    Aritmetica(int a, int b) //Constructor parametrizado
    {
        this.a = a;
        this.b = b;
    }
    
    public int suma(int arg1, int arg2) //Metodo suma parametrizado
    {
        return arg1 + arg2;
    }
    
    public int suma() //Metodo suma sin parametros
    {
        return a + b;
    }
    
    //SOBRECARGA DE METODOS
    
    //1 - El nombre del metodo debe ser el mismo del que quiero sobrecargar
    //2 - Los argumentos deben ser distintos
    //3 - El tipo de retorno no afecta si es igual o distinto
    //4 - El metodo a sobrecargar puede estar definido en nuestra clase o clase superior.
    //5 - Los argumentos pueden ser del tipo primitivo o Object.
    
    public int suma(double x, double y)
    {
        System.out.println("Suma de dos double: ");
        return (int) (x+y);
    }
    
    public static void main(String[] args) {
        
        Aritmetica a1 = new Aritmetica();
        System.out.println("Resultado A1: " + a1.suma(5, 3));
        
        Aritmetica a2 = new Aritmetica(1, 2);
        System.out.println("La suma sin parametros es: " + a2.suma());
        
        Aritmetica a3 = new Aritmetica();
        System.out.println("El resultado es: " + a3.suma(6.5, 7.3));
        
    }
    
}
