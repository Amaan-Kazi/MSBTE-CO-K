import java.awt.*;

public class exp14_1 extends Frame {
  exp14_1() {
    setSize(300, 300);
    setVisible(true);
    setLayout(new FlowLayout());

    Checkbox c1 = new Checkbox("World");

    CheckboxGroup group = new CheckboxGroup();
    Checkbox r1 = new Checkbox("Hello", group, false);

    add(r1);
    add(c1);
  }

  public static void main(String args[]) {
    new exp14_1();
  }
}
