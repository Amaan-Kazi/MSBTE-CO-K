import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class exp20_3 extends JFrame implements KeyListener {
  private JLabel tf;
  
  exp20_3 () {
    setSize(500, 500);
    setLayout(new FlowLayout());

    tf = new JLabel("press any key");
    add(tf);

    addKeyListener(this);
    setVisible(true);
  }

  public void keyPressed(KeyEvent e) {
    tf.setText("Key Pressed: " + e.getKeyChar());
  }
  public void keyReleased(KeyEvent e) {}
  public void keyTyped(KeyEvent e) {}

  public static void main(String args[]) {
    new exp20_3();
  }
}
