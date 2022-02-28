package paquete;

public class Carro {
	
	double peso;
	double altura;
	double ancho;
	double largo;
	int numeroPuertas;
	String modelo;
	
	
	public Carro()
	{
		this.peso = 2000;
		this.altura = 2;
		this.ancho = 30;
		this.largo = 3;
		this.numeroPuertas = 4;
		
		
	}
	public Carro(float peso, float altura, float ancho, float largo, int numeroPuertas )
	{
		this.altura = altura;
		this.ancho = ancho;
		this.peso = peso;
		this.largo = largo;
		this.numeroPuertas = numeroPuertas;
	}

	public void mostrarPuertas()
	{
			System.out.println("Las puertas son: "+numeroPuertas);
	}
	
	public void verCarro()
	{
		System.out.println("Peso: "+peso+" Altura: "+altura+" Ancho: "+ancho+" Largo; "+largo+" Numero puertas: "+numeroPuertas);

		
	}
	public void verModeloCarro()
	{
		System.out.println("El modelito es normal");
		
	}
}

///HERENCIA ES COMO EL HIJO DE CARRO, PUEDE SER EL MODELO DEL CARRO
	class CarroBMW extends Carro
	{
		public void CarroBMW()
		{
			this.modelo = "BMW";
			
			
		}
		
		public void turbo()
		{
			System.out.println("Acabas de acelerar con tu BMW");
			
		}
		public void verModeloCarro()
		{
			System.out.println("El modelito es BMW");
			
		}
		
		
		
	}
	class CarroToyota extends Carro
	{
		public void carroToyota()
		{
			this.modelo = "Toyota";
		}
		public void verModeloCarro()
		{
			System.out.println("El modelito es Toyota");
			
		}
		
	}
	

