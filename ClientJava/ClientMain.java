import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ClientMain extends JFrame{

    private static final long serialVersionUID = 1L;
	static final String HOST = "localhost";
	static final int PORT = 3331;
	private static Client client = null;

	JTextArea textArea = new JTextArea(10, 20);
	JButton search, play, close;
	JPanel panel;
	JScrollPane scroll;
	JTextField textField;
	JLabel label;

	JMenuBar menuBar = new JMenuBar();
	JMenu menu, edit, media = new JMenu();
	JToolBar toolBar = new JToolBar();

    /*
    JTextArea myTextBox;
    JPanel jp;
    JScrollPane jsp;
    JMenuBar jmb;
    JToolBar jtb;*/

    public static void main(String argv[]){
        new ClientMain();
    	String host = HOST;
    	int port = PORT;
    	if (argv.length >= 1) host = argv[0];
    	if (argv.length >= 2) port = Integer.parseInt(argv[1]);

    	try {
    		client = new Client(host, port);
    	} catch (Exception e) {
    		System.err.println("Client: Couldn't connect to "+host+":"+port);
    	    System.exit(1);
    	}

        System.out.println("Client connected to "+host+":"+port);
    }

    public ClientMain(){
        /*
        // Declaration
        JButton b1, b2, b3;
        JMenu jmActions;
        JMenuItem jmiB1, jmiB2, jmiB3;

        // Initialization
        jp = new JPanel();
        add(jp, BorderLayout.SOUTH);
        myTextBox = new JTextArea("Hello World!\n", 3, 25);
        jsp = new JScrollPane(myTextBox);
        add(jsp);
        b1 = new JButton("Button1");
        b2 = new JButton("Button2");
        b3 = new JButton("Button3");
        jp.add(b1); jp.add(b2); jp.add(b3);
        // JMenuBar
        jmb = new JMenuBar();
        setJMenuBar(jmb);
        // JMenu
        jmActions = new JMenu("Actions");
        jmActions.add(new JMenuItem(new AbstractButton1("B1")));
        jmActions.add(new JMenuItem(new AbstractButton2("B2")));
        jmActions.add(new JMenuItem(new AbstractButton3("Exit")));
        jmb.add(jmActions);
        // ToolBar
        jtb = new JToolBar();
        jtb.add(new JButton(new AbstractButton1("B1")));
        jtb.add(new JButton(new AbstractButton2("B2")));
        jtb.add(new JButton(new AbstractButton3("Exit")));
        jmb.add(jtb);

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
    }*/
		setLayout(new BorderLayout());

		add(textArea, BorderLayout.CENTER);
		add(scroll = new JScrollPane(textArea));

		add(panel = new JPanel(), BorderLayout.SOUTH);

		panel.add(label = new JLabel("Object name: "));
		panel.add(textField = new JTextField(20));
		panel.add(search = new JButton("Search"));
		panel.add(play = new JButton("Play"));
		panel.add(close = new JButton("Close"));

		search.addActionListener(new SearchListener());
		play.addActionListener(new PlayListener());
		close.addActionListener(new CloseListener());

		add(toolBar, BorderLayout.NORTH);
		setJMenuBar(menuBar);
		menuBar.add(menu = new JMenu("Menu"));

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}

	class SearchListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			String name = "info " + textField.getText();
			String s = client.send(name) + "\n";
            s = s.replace(";","\n");
			textArea.append(s);
		}

	}

	class PlayListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			String name = "play " + textField.getText();
			String s = client.send(name) + "\n";
            s = s.replace(";","\n");
			textArea.append(s);
		}

	}

	class CloseListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
            String s = client.send("quit") + "\n";
			textArea.append(s);
			System.exit(0);
		}

	}

}
