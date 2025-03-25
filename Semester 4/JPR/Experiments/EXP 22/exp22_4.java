import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class exp22_4 extends JFrame implements ActionListener {
  private JTextField n1, n2, result;
  private JButton addButton;

  exp22_4() {
    setSize(400, 300);
    setLayout(new GridLayout(3, 2));

    n1 = new JTextField(12);
    n2 = new JTextField(12);
    addButton = new JButton("Add");
    result = new JTextField(12);

    add(new JLabel("Num1: "));
    add(n1);
    add(new JLabel("Num2: "));
    add(n2);
    add(addButton);
    add(result);

    addButton.addActionListener(this);
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == addButton) {
      int num1 = Integer.parseInt(n1.getText());
      int num2 = Integer.parseInt(n2.getText());
      result.setText("" + (num1 + num2));
    }
  }

  public static void main(String args[]) {
    new exp22_4();
  }  
}
