# ICPC-Notebook-HCMUS-PenguinSpammers
Notebook of ICPC team: HCMUS-PenguinSpammers  

## Installation
### Install notebook-generator
```bash
    sudo apt install texlive texlive-latex-extra
    sudo npm install -g notebook-generator
```

### Install and build notebook
```bash
    git clone https://github.com/vanloc1808/ICPC-Notebook-HCMUS-PenguinSpammers
    cd ICPC-Notebook-HCMUS-PenguinSpammers
    notebook-generator ./content/ --output doc/ICPCNotebooks-HCMUS-PenguinSpammers.pdf --author "HCMUS-PenguinSpammers" --columns 3 --paper a4paper --size 9 --initials HCMUS
```
### Options
```bash
    -V, --version             output the version number
    -a --author <name>        author's name to be added in the notebook
    -i --initials <initials>  initials of the author to be placed in the upper-right corner of all pages
    -o --output <filename>    output file for the notebook. (default: "./notebook.pdf")
    -s --size <size>          font size is allowed 8, 9, 10, 11, 12, 14, 17, 20 pt (default: "10")
    -c --columns <amount>     number of columns is allowed 2, 3. (default: "2")
    -p --paper <size>         paper size is allowed letterpaper, a4paper, a5paper. (default: "letterpaper")
    -h, --help                output usage information
    -I --image <source>       cover image to be added in the notebook.
```

## References
- [notebook-generator tool](https://github.com/pin3da/notebook-generator)
- [https://github.com/huynhtuan17ti/ICPC-Notebook](https://github.com/huynhtuan17ti/ICPC-Notebook)
- [KTH Royal Institute of Technology](https://github.com/kth-competitive-programming/kactl)