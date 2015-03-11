package org.elsys_bg.abonatnik.rest;

import java.util.HashMap;
import java.util.Map;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;

import org.elsys_bg.abonatnik.model.Student;

@Path("abonatnik")
public class StudentResource {
	static Map<Integer, Student> students = new HashMap<Integer, Student>();
	static int currentId = 1;
	
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	public Map<Integer, Student> getAllStudents() {
		System.out.println(students);
		return students;
	}
	
	@GET
	@Produces(MediaType.APPLICATION_JSON)
	@Path("{id}")
	public Student getStudent(@PathParam("id") String id, @QueryParam("filter") String filter) {
		if(students.containsKey(Integer.parseInt(id))) {
			return students.get(Integer.parseInt(id));
		}
		throw new IllegalArgumentException();
	}
	
	@POST
	@Consumes(MediaType.APPLICATION_JSON)
	public void addStudent(Student student) {
		while(true) {
			if(students.containsKey(currentId)) {
				currentId++;
			} else {
				break;
			}
		}
		students.put(currentId, student);
		currentId++;
	}
	
	@PUT
	@Path("{id}")
	public void modifyStudent(@PathParam("id") String id, Student student) {
		if(students.containsKey(Integer.parseInt(id))) {
			students.put(Integer.parseInt(id), student);
		} 
		throw new IllegalArgumentException();
	}
}
