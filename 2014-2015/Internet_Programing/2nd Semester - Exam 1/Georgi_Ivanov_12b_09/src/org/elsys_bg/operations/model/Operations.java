package org.elsys_bg.operations.model;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class Operations {
	private String expr;
	private int result;
	
	public Operations(){}
	
	public String getExpr() {
		return expr;
	}
	public void setExpr(String expr) {
		this.expr = expr;
	}
	public int getResult() {
		return result;
	}
	public void setResult(int result) {
		this.result = result;
	}
}
