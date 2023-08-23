/**
 * _myhistory - displaying the history listed, one commands by line, preceded
 *              with lines numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant functions prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to the string
 * @info: parameter structed
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *m, f;
	int ret;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	f = *m;
	*m = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*m = f;
	return (ret);
}

/**
 * set_alias - sets alias to the string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *m;

	m = _strchr(str, '=');
	if (!m)
		return (1);
	if (!*++m)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - printing an alias string
 * @node: the alias nodes
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *m = NULL, *c = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (c = node->str; c <= m; a++)
		_putchar(*m);
		_putchar('\'');
		_puts(m + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int n = 0;
	char *m = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (n = 1; info->argv[i]; i++)
	{
		m = _strchr(info->argv[i], '=');
		if (m)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

