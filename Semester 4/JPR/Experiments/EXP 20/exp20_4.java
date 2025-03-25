import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class exp20_4 extends JFrame implements MouseMotionListener {
  JLabel label;

  public exp20_4() {
    setSize(400, 300);
    setLayout(new FlowLayout());

    label = new JLabel("Move or drag the mouse", SwingConstants.CENTER);
    add(label);

    addMouseMotionListener(this);
    setVisible(true);
  }

  public void mouseDragged(MouseEvent e) {
    label.setText("Mouse Dragged at X: " + e.getX() + " Y: " + e.getY());
  }

  public void mouseMoved(MouseEvent e) {
    label.setText("Mouse Moved at X: " + e.getX() + " Y: " + e.getY());
  }

  public static void main(String[] args) {
    new exp20_4();
  }
}
