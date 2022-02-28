package paquete;
import java.util.LinkedList;
public class Main {
	/*
	 * offer Añadir un dato
	 * poll obtener un dato y elimina
	 * */

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//FIFO firt.in, first,out
		LinkedList cola = new LinkedList();
		//Mostrar por pantalla del 1 al 10 mediente una cola
		for(int i=0;i<11;i++)
			cola.offer(i);
		while(cola.peek()!= null)
		{
			System.out.println(cola.poll());
			
		}
	}

}
