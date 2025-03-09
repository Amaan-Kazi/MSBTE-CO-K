import java.awt.*;

public class exp14_2 extends Frame {
  exp14_2() {
    setSize(300, 300);
    setVisible(true);
    setLayout(new GridLayout(4, 1));

    Label l1 = new Label("This is a label");
    Button b1 = new Button("This is a button");
    TextField tf1 = new TextField(2);
    TextArea ta1 = new TextArea(4, 2);

    add(l1);
    add(b1);
    add(tf1);
    add(ta1);
  }

  public static void main(String args[]) {
    new exp14_2();
  }
}
