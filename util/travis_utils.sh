# Use this by sourcing it in your script.

# Provide sane defaults for travis environment
TRAVIS_BRANCH="${TRAVIS_BRANCH:master}"
TRAVIS_PULL_REQUEST="${TRAVIS_PULL_REQUEST:false}"
TRAVIS_COMMIT_MESSAGE="${TRAVIS_COMMIT_MESSAGE:-none}"
TRAVIS_COMMIT_RANGE="${TRAVIS_COMMIT_RANGE:-HEAD~1..HEAD}"

# test force push
#TRAVIS_COMMIT_RANGE="c287f1bfc5c8...81f62atc4c1d"

# Extra variables
LOCAL_BRANCH=${TRAVIS_PULL_REQUEST_BRANCH:-${TRAVIS_BRANCH}}
QMK_CHANGES=$(git diff --name-only HEAD ${TRAVIS_BRANCH})

# if docker is installed - patch calls to within the qmk docker image
if command -v docker >/dev/null; then
    function make() {
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        set
        echo
        echo docker run --rm -e MAKEFLAGS="$MAKEFLAGS" -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container make "$@"
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        docker run --rm -e MAKEFLAGS="$MAKEFLAGS" -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container make "$@"
    }
    function qmk() {
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        set
        echo
        echo docker run --rm -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container bin/qmk "$@"
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        echo DEBUG DEBUG DEBUG DEBUG DEBUG
        docker run --rm -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container bin/qmk "$@"
    }
fi