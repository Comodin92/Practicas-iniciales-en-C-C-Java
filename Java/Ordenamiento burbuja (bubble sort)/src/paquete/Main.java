package paquete;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []arreglo = {5,3,4,2,66,51,332,0,9,199,100};
		Ordenador o = new Ordenador();
		o.ordenQuicksort(arreglo);
		for(int i=0; i < arreglo.length ;i++)
			System.out.println(arreglo[i]);
	}

}
