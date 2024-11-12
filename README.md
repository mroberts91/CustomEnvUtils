# CustomEnvUtils
One off utils for Debian Dev Env

### Development
1. Clone the `util-template` dir, which contains a project boilerplate, Makefile and deploy script.
2. Write your `C` util
3. `make run` will build into the local `bin` dir for dev execution.

### Deployment
`deploy.sh` make the assumption that `/home/[USER]/bin` exists and is added to the profile `PATH` for user-only utils.
1. Execute `deploy.sh`. This will build and copy the binary to your profile `bin`.
