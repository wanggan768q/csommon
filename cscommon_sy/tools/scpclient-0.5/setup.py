import sys
from distutils.core import setup, Command

name = 'scpclient'
if 'bdist_rpm' in sys.argv:
    name = 'python-' + name

setup(name=name,
      version='0.5',
      url='https://bitbucket.org/ericvsmith/scpclient',
      author='Eric V. Smith',
      author_email='eric@trueblade.com',
      description='scp client, for use with paramiko.',
      long_description=open('README.txt').read() + '\n' + open('CHANGES.txt').read(),
      classifiers=['Development Status :: 4 - Beta',
                   'Intended Audience :: Developers',
                   'License :: OSI Approved :: Apache Software License',
                   'Topic :: Software Development :: Libraries :: Python Modules',
                   'Topic :: Security :: Cryptography',
                   'Programming Language :: Python :: 2.6',
                   'Programming Language :: Python :: 2.7',
                   ],
      license='Apache License Version 2.0',
      py_modules=['scpclient'],
      )
