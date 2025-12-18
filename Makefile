.PHONY: help git-status git-add git-commit git-push git-pull git-log git-branch git-merge

help:
	@echo "Available git commands:"
	@echo "  make git-status   - Show git status"
	@echo "  make git-add      - Add all changes"
	@echo "  make git-commit   - Commit with message"
	@echo "  make git-push     - Push to remote"
	@echo "  make git-pull     - Pull from remote"
	@echo "  make git-log      - Show commit log"
	@echo "  make git-branch   - List branches"
	@echo "  make git-merge    - Merge branches"

git-status:
	git status

git-add:
	git add .

git-commit:
	git commit -m "$(MSG)"

git-push:
	git push origin $(BRANCH)

git-pull:
	git pull origin $(BRANCH)

git-log:
	git log --oneline -10

git-branch:
	git branch -a

git-merge:
	git merge $(BRANCH)