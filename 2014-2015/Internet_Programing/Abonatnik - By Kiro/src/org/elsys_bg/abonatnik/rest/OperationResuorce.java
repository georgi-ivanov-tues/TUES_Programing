package org.elsys_bg.abonatnik.rest;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.elsys_bg.abonatnik.model.Operation;

@Path("operations")
public class OperationResuorce {
	
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	@Path("{operation}/{fnumber}/{snumber}")
	public Operation doOperation(@PathParam("operation") String operation,
								@PathParam("fnumber") String fnumber,
								@PathParam("snumber") String snumber){
		Operation operationObject = new Operation(Double.parseDouble(fnumber), Double.parseDouble(snumber), operation);
		System.out.println(operationObject.getExpr());
		System.out.println(operationObject.getResult());
		return operationObject;
	}
}
