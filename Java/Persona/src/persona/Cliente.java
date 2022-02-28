/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package persona;
import java.util.Date;

/**
 *
 * @author Agus
 */
public class Cliente extends Persona {
    
    private int idCliente;
    private Date fechaRegistro;
    private boolean vip;
    
    
    //Constructor x defecto
    Cliente(){
    }
    
    //Constructor parametrizado
    Cliente(int id, Date fecha, boolean vip)
    {
        this.idCliente = id;
        this.fechaRegistro = fecha;
        this.vip = vip;
    }
    
    //Getters
    public int obtenerIdCliente(){
        return this.idCliente;
    }
   
    //Setters
    public void modificarIdCliente(int id){
        this.idCliente = id;
    }
    
    //Mostrar
    public void mostrarCliente()
    {
        System.out.println("ID Cliente: " + this.idCliente);
        System.out.println("Fecha registro: " + this.fechaRegistro);
        System.out.println("VIP: " + this.vip);
    } 

    @Override
    public String toString() {
        return super.toString() + "Cliente{" + "idCliente=" + idCliente + ", fechaRegistro=" + fechaRegistro + ", vip=" + vip + '}';
    }
    
    
}
