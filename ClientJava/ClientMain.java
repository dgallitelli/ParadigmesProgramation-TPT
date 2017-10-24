import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ClientMain extends JFrame{

    private static final long serialVersionUID = 1L;

    JTextArea myTextBox;
    JPanel jp;
    JScrollPane jsp;
    JMenuBar jmb;
    JToolBar jtb;

    public static void main(String argv[]){
        new ClientMain();
    }

    public ClientMain(){
        // Declaration
        JButton b1, b2, b3;
        JMenu jmActions;
        JMenuItem jmiB1, jmiB2, jmiB3;

        // Initialization
        jp = new JPanel();
        b1 = new JButton("Button1");
        b2 = new JButton("Button2");
        b3 = new JButton("Button3");
        myTextBox = new JTextArea("Hello World!\n", 3, 25);
        jsp = new JScrollPane(myTextBox);
        // MenuBar
        jmb = new JMenuBar();
        jmActions = new JMenu("Actions");
        jmiB1 = new JMenuItem(new AbstractButton1("B1"));
        jmiB2 = new JMenuItem(new AbstractButton2("B2"));
        jmiB3 = new JMenuItem(new AbstractButton3("Exit"));
        // ToolBar
        jtb = new JToolBar();

        // Add components to the JFrame
        setJMenuBar(jmb); add(jtb);
        add(jp, BorderLayout.SOUTH); add(jsp);
        jp.add(b1); jp.add(b2); jp.add(b3);
        jmb.add(jmActions); jmActions.add(jmiB1); jmActions.add(jmiB2); jmActions.add(jmiB3);

        // Setup listeners
        /*
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
        });*/
        b1.addActionListener(new AbstractButton1("B1"));
        b2.addActionListener(new AbstractButton2("B2"));
        b3.addActionListener(new AbstractButton3("Exit"));

        // Run the code
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Top-Box Client");
        pack();
        setVisible(true);
    }

    public class AbstractButton1 extends AbstractAction{
        AbstractButton1(String text){
            super(text);
        }
        public void actionPerformed(ActionEvent e){
            myTextBox.append("Hello from Button 1!\n");
        }
    }
    public class AbstractButton2 extends AbstractAction{
        AbstractButton2(String text){
            super(text);
        }
        public void actionPerformed(ActionEvent e){
            myTextBox.append("Hello from Button 2!\n");
        }
    }
    public class AbstractButton3 extends AbstractAction{
        AbstractButton3(String text){
            super(text);
        }
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
    }

}
