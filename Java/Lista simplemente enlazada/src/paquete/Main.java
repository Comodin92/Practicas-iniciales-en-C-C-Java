package paquete;
import java.util.LinkedList;
public class Main {
///Aca no se crean primitivas, siempre se usan las funciones de biblioteca
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList lista = new LinkedList();
		
		lista.add("Damian");
		lista.add(76);
		///Se puede indicar en que posicion insertarlo lista.add(1,40); index, dato
		System.out.println(lista.size());
		///Usamos get para obtener un dato en especifico getfirst, getLast
		System.out.println(lista.get(0));
	}

}
