package org.elsys.graphics_2014;


import java.awt.Point;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.MouseMoveListener;
import org.eclipse.swt.events.PaintEvent;
import org.eclipse.swt.events.PaintListener;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;

public class Main {

	private static Point firstPoint = null;
	private static Point secondPoint = null;
	
	public static void main(String[] args){
		Display d = new Display();
		Shell shell = new Shell(d);
		shell.setLayout(new FillLayout(SWT.HORIZONTAL));
		Canvas c = new Canvas(shell, SWT.NONE);
		c.setBackground(Display.getCurrent().getSystemColor(SWT.COLOR_RED));
		
		shell.open();
		
		createPaintListener(c);
		createMouseListener(c);
		createMoveListener(c);
		while(!shell.isDisposed()){
			if(!d.readAndDispatch()){
				d.sleep();
			}
		}
	}

	private static void createMoveListener(final Canvas c) {
		c.addMouseMoveListener(new MouseMoveListener() {
			
			@Override
			public void mouseMove(MouseEvent e) {
				if(firstPoint != null && secondPoint == null){
					GC gc = new GC(c);
					gc.drawLine(firstPoint.x, firstPoint.y, e.x, e.y);
					gc.dispose();
				}
			}
		});
	}

	private static void createMouseListener(final Canvas c) {
		c.addMouseListener(new MouseListener() {
			
			@Override
			public void mouseUp(MouseEvent arg0) {
				
			}
			
			@Override
			public void mouseDown(MouseEvent e) {
				if(firstPoint == null && secondPoint == null)
					firstPoint = new Point(e.x,e.y);
					//firstPoint, secondPoint == null
				else if(firstPoint != null && secondPoint == null){
					GC gc = new GC(c);
					secondPoint = new Point(e.x,e.y);
					gc.drawLine(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y);
					firstPoint = null;
					secondPoint = null;
					gc.dispose();
				}
				
//				GC gc = new GC(c);
//				gc.drawOval(e.x, e.y, 10, 10);
//				gc.dispose();
			}
			
			@Override
			public void mouseDoubleClick(MouseEvent arg0) {
				
			}
		});
	}

	private static void createPaintListener(Canvas c) {
		c.addPaintListener(new PaintListener() {
			
			@Override
			public void paintControl(PaintEvent e) {
//				GC gc = e.gc;
//				gc.drawLine(0, 0, 100, 100);
//				gc.drawRectangle(100, 100, 100, 100);
				//Image image = new Image(e.display,"/home/student11b/Desktop/Other/cats.jpg");
				//gc.drawImage(image, 200, 0);
			}
		});
	}
}

//lain-a
