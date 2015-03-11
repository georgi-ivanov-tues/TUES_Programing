package org.elsys_bg.abonatnik.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class Operation {
	private String expr;
	private double result;
	
	public Operation() {
		
	}
	
	public Operation(double x, double y, String operation) {
		switch(operation) {
		case "add": expr = x + " + " + y;
					result = x + y;
					break;
		case "multiply": expr = x + " * " + y;
						 result = x * y;
						 break;
		case "subtract": expr = x + " - " + y;
						 result = x - y;
						 break;
		}
	}

	public String getExpr() {
		return expr;
	}

	public void setExpr(String expr) {
		this.expr = expr;
	}

	public double getResult() {
		return result;
	}

	public void setResult(double result) {
		this.result = result;
	}
}
