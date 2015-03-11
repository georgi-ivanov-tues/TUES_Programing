package org.elsys_bg.operations.rest;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.elsys_bg.operations.model.Operations;

@Path("operations")
public class OperationsResource {

	@GET
	@Produces(MediaType.APPLICATION_JSON)
	@Path("{operation}/{fNumber}/{Snumber}")
	public Operations operation(@PathParam("operation") String operation, @PathParam("fNumber") String fNumber, @PathParam("Snumber") String Snumber) {
		Operations newOp = new Operations();
		
		int result = 0;
		if(operation.equals("add")){
			newOp.setExpr(fNumber + " + " + Snumber);
			result = Integer.parseInt(fNumber) + Integer.parseInt(Snumber);
		}else if(operation.equals("multiply")){
			newOp.setExpr(fNumber + " * " + Snumber);
			result = Integer.parseInt(fNumber) * Integer.parseInt(Snumber);
		}else if(operation.equals("substract")){
			newOp.setExpr(fNumber + " - " + Snumber);
			result = Integer.parseInt(fNumber) - Integer.parseInt(Snumber);
		}
		
		newOp.setResult(result);
		return newOp;
	}
}