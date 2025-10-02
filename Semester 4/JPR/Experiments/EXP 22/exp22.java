import java.awt.*;

public class exp22 extends Frame {
  exp22() {
    setSize(500, 500);
    setLayout(new GridBagLayout());
    GridBagConstraints gbc = new GridBagConstraints();

    gbc.gridx = 0;
    gbc.gridy = 0;
    add(new Label("Name"), gbc);

    gbc.gridx = 1;
    gbc.gridy = 0;
    add(new TextField(12), gbc);

    gbc.gridx = 0;
    gbc.gridy = 1;
    add(new Label("Comment"), gbc);

    gbc.gridx = 1;
    gbc.gridy = 1;
    add(new TextArea(6, 12), gbc);

    gbc.gridx = 1;
    gbc.gridy = 2;
    add(new Button("Submit"), gbc);

    setVisible(true);
  }

  public static void main(String args[]) {
    new exp22();
  }
}
