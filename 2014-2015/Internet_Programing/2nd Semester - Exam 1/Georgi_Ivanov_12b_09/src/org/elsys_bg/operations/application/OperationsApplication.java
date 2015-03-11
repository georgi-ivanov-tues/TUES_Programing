package org.elsys_bg.operations.application;

import javax.ws.rs.ApplicationPath;
import org.glassfish.jersey.server.ResourceConfig;

@ApplicationPath("Operations")
public class OperationsApplication extends ResourceConfig {
	
	public OperationsApplication(){
		packages("org.elsys_bg.operations.rest");
	}
	
}
