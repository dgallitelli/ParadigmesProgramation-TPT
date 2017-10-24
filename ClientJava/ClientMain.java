import javax.swing.*;
import java.awt.event.*;

public class ClientMain extends JFrame{
    JTextArea myTextBox;
    JButton b1, b2, b3;

    public static void main(String argv[]){

        new ClientMain();
    }

    public ClientMain(){
        // Initialization
        b1 = new JButton("Button1");
        b2 = new JButton("Button2");
        b3 = new JButton("Button3");
        myTextBox = new JTextArea("Hello World!", 3, 25);

        // add components to the controlPane
        add(myTextBox); add(b1); add(b2); add(b3);

        // Setup listeners
        b1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                myTextBox.append("Hello from Button 1!");
            }
        });
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                myTextBox.append("Hello from Button 2!");
            }
        });
        b3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

        // Run the code
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Top-Box Client");
        pack();
        setVisible(true);
    }

}
