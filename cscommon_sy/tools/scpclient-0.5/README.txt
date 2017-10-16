---------
scpclient
---------

A library that implements the client side of the scp (Secure Copy)
protocol. It is designed to be used with paramiko
(http://www.lag.net/paramiko/).

Using paramiko
==============

There are many ways to use paramiko. For the purposes of these
examples, you want to obtain an authenticated SSHClient object::

    import paramiko

    ssh_client = paramiko.SSHClient()
    ssh_client.connect(hostname, username=username, key_filename=key_filename, password=password)

Writing files
=============

The scpclient.Write object is used to write files to an scp
server. Its required parameters are a paramiko.SSHClient instance and
a remote directory name. It has 2 methods: send_file and
send. send_file takes a filename to send, send takes a file-like
object, a remote filename, a mode, and a length. You may call send and
send_file multiple times.

Example::

    with closing(Write(ssh_client.get_transport(), '.')) as scp:
        scp.send_file('file.txt', True)
        scp.send_file('../../test.log', remote_filename='baz.log')

        s = StringIO('this is a test')
        scp.send(s, 'test', '0601', len(s.getvalue()))

Writing directories
===================

Example::

    with closing(WriteDir(ssh_client.get_transport(), 'subdir')) as scp:
        scp.send_dir('../../manuals', preserve_times=True, progress=progress)

Reading files
=============

Example::

    with closing(ReadDir(ssh_client.get_transport(), '.')) as scp:
        scp.receive_dir('foo', preserve_times=True)

Reading directories
===================

Example::

    with closing(Read(ssh_client.get_transport(), '.')) as scp:
        scp.receive('file.txt')

