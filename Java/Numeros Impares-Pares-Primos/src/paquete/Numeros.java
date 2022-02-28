package paquete;

class Numeros {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int numero,suma=0;
		
		for(numero=1;numero <=20;numero ++)
		{
			if(numero%2==0)
				System.out.println("Numero Par: "+numero);
			if(numero%2!=0)
				System.out.println("Numero Impar: "+numero);
			
			suma+=numero;
		}
		System.out.println("La suma total es: "+suma);


	}

}
