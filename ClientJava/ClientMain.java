import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ClientMain extends JFrame{

    private static final long serialVersionUID = 1L;

    JTextArea myTextBox;
    JButton b1, b2, b3;
    JPanel jp;

    public static void main(String argv[]){

        new ClientMain();
    }

    public ClientMain(){
        // Initialization
        jp = new JPanel();
        b1 = new JButton("Button1");
        b2 = new JButton("Button2");
        b3 = new JButton("Button3");
        myTextBox = new JTextArea("Hello World!\n", 3, 25);

        // add components to the controlPane
        add(jp, BorderLayout.SOUTH);
        add(myTextBox); jp.add(b1); jp.add(b2); jp.add(b3);

        // Setup listeners
        b1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                myTextBox.append("Hello from Button 1!\n");
            }
        });
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                myTextBox.append("Hello from Button 2!\n");
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
